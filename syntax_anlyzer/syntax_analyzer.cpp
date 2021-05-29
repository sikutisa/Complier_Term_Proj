#include "slr_table.h"
#include "syntax_analyzer.h"

int main(int argc, char* argv[])
{
	ifstream readTXT;
	readTXT.open(argv[1]);
	stack<string> prefix;
	queue<pair<string, string>> input;
	stack<int> SLR_Stack;

	if (readTXT.is_open())
	{
		while (!readTXT.eof())
		{
			string inputbuffer;
			string temp;
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
	pair<string, string> nextInput = input.front();
	SLR_Stack.push(0); // initial state
	int count = 1;
	while (!SLR_Stack.empty())
	{
		action = actionTable[SLR_Stack.top()][actionHashMap[nextInput.first]];
		if (action == ACCEPT)
			break;
		// reduce & goto
		else if (action > 99)
		{
			action %= 100;
			action--;
			for (int i = 0; i < CFG[action].second; ++i)
			{
				prefix.pop();
				SLR_Stack.pop();
			}
			prefix.push(CFG[action].first);
			SLR_Stack.push(gotoTable[SLR_Stack.top()][gotoHashMap[prefix.top()]]);
		}
		// shift
		else
		{
			SLR_Stack.push(action);
			prefix.push(nextInput.first);
			input.pop();
			nextInput = input.front();
			count++;
		}

		if (SLR_Stack.top() == -1)
		{
			cout << "Error!:" << endl;
			if(nextInput.second.empty())
				cout << "At " << "<" << nextInput.first << ">";
			else
				cout << "At " << "<" << nextInput.first << ", " << nextInput.second << ">";
			cout << "(" << count << "th input)" << endl;
			return -1;
		}
	}
	cout << "Accept!";
	return 0;
}

void makeInputFormat(string& temp, queue<pair<string, string>>& input)
{
	string token;
	string value;
	string inputToken;
	if (temp.find(",") == string::npos)
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