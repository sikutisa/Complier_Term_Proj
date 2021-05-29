#include "slr_table.h"
#include "syntax_analyzer.h"

int main(int argc, char* argv[])
{
	std::ifstream readTXT;
	readTXT.open(argv[1]);
	std::deque<std::string> prefix;
	std::queue<std::pair<std::string, std::string>> input;
	std::stack<int> SLR_Stack;
	SLR_Stack.push(0); // initial state

	if (readTXT.is_open())
	{
		while (!readTXT.eof())
		{
			std::string inputbuffer;
			std::string temp;
			getline(readTXT, inputbuffer);
			if (!inputbuffer.empty())
			{
				temp = inputbuffer.substr(1, inputbuffer.size() - 2);
				makeInputFormat(temp, input);
			}
		}
		readTXT.close();
		input.push(make_pair("$", ""));
	}

	int action = 0;
	while (action != ACCEPT)
	{
		std::pair<std::string, std::string> nextInput = input.front();
		int action = actionTable[SLR_Stack.top()][actionHashMap[nextInput.first]];
		// reduce & goto
		if (action > 99)
		{
			action %= 100;

		}
		// shift
		else
		{
			prefix.push_back(nextInput.first);
			SLR_Stack.push(action);
		}
		input.pop();
	}
	
	return 0;
}

void makeInputFormat(std::string& temp, std::queue<std::pair<std::string, std::string>>& input)
{
	std::string token;
	std::string value;
	std::string inputToken;
	if (temp.find(",") == std::string::npos)
	{
		inputToken = temp;
		value = "";
	}
	else
	{
		inputToken = temp.substr(0, temp.find(","));
		value = temp.substr(temp.find(",") + 2, temp.size() - temp.find(",") - 1);
	}
	if (inputToken == "ARITH")
	{
		if (value == "+" || value == "-")
			token = "addsub";
		else
			token = "muldiv";
	}
	else if (inputToken == "VARTYPE")
		token = "vtype";
	else if (inputToken == "IDENTIFIER")
		token = "id";
	else if (inputToken == "SEMI")
		token = "semi";
	else if (inputToken == "ASSIGN")
		token = "assign";
	else if (inputToken == "LITERAL")
		token = "literal";
	else if (inputToken == "CHAR")
		token = "character";
	else if (inputToken == "BOOLEAN")
		token = "boolstr";
	else if (inputToken == "LPAREN")
		token = "lparen";
	else if (inputToken == "RPAREN")
		token = "rparen";
	else if (inputToken == "INT")
		token = "num";
	else if (inputToken == "LBRACE")
		token = "lbrace";
	else if (inputToken == "RBRACE")
		token = "rbrace";
	else if (inputToken == "COMMA")
		token = "comma";
	else if (inputToken == "IF")
		token = "if";
	else if (inputToken == "WHILE")
		token = "while";
	else if (inputToken == "COMPARE")
		token = "comp";
	else if (inputToken == "ELSE")
		token = "else";
	else if (inputToken == "RETURN")
		token = "return";
	else if (inputToken == "CLASS")
		token = "class";
	input.push(make_pair(token, value));
}