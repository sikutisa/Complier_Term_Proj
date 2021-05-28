#include "dfa.h"

// dfa에 따라 주어진 문자열을 분석한다
// 탐색하고자 하는 Token과 일치하면 해당 Token 길이 만큼 start를 이동시켜 준다.
// 다른 Token이라면, 이동시키지 않는다.

// CHAR를 구현하기 위한 LETTER 판별용
bool isLetter(char c)
{
	if (isalpha(c) || isdigit(c) || c == ' ')
		return true;
	return false;
}

//INT를 구현하기 위한 DIGIT과 NATURALNUM
bool isNaturalNum(char c)
{
	if (isdigit(c) && c != '0')
		return true;
	return false;
}

bool isDigit(char c)
{
	if (isdigit(c))
		return true;
	return false;
}

// VARTYPE은 int, char, String, Boolean만 올 수 있으며 IDENTIFIER와 구분하기 위해 뒤에 whitespace가 있는지 체크해야 한다.
// VARTYPE만 주어진 경우, 뒤를 참조할 수 없기 때문에, 입력된 문자열의 길이에 따라 처리를 해준다.
Token isVarType(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.substr(start, 3) == "int" && start + 3 == str.length())
	{
		result.initialToken(VARTYPE, "int");
		start += 3;
	}
	else if (str.substr(start, 3) == "int" && isspace(str.at(start + 3)))
	{
		result.initialToken(VARTYPE, "int");
		start += 3;
	}
	if (str.substr(start, 4) == "char" && start + 4 == str.length())
	{
		result.initialToken(VARTYPE, "char");
		start += 4;
	}
	else if (str.substr(start, 4) == "char" && isspace(str.at(start + 4)))
	{
		result.initialToken(VARTYPE, "char");
		start += 4;
	}
	else if (str.substr(start, 6) == "String" && start + 6 == str.length())
	{
		result.initialToken(VARTYPE, "String");
		start += 6;
	}
	else if (str.substr(start, 6) == "String" && isspace(str.at(start + 6)))
	{
		result.initialToken(VARTYPE, "String");
		start += 6;
	}
	else if (str.substr(start, 7) == "Boolean" && start + 7 == str.length())
	{
		result.initialToken(VARTYPE, "Boolean");
		start += 7;
	}
	else if (str.substr(start, 7) == "Boolean" && isspace(str.at(start + 7)))
	{
		result.initialToken(VARTYPE, "Boolean");
		start += 7;
	}
	return result;
}

// 나머지 사이즈가 1인 Token을 판별한다
Token isExtraToken(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.at(start) == ',')
	{
		result.initialToken(COMMA, "");
		start++;
	}
	else if (str.at(start) == '{')
	{
		result.initialToken(LBRACE, "");
		start++;;
	}
	else if (str.at(start) == '}')
	{
		result.initialToken(RBRACE, "");
		start++;;
	}
	else if (str.at(start) == '(')
	{
		result.initialToken(LPAREN, "");
		start++;;
	}
	else if (str.at(start) == ')')
	{
		result.initialToken(RPAREN, "");
		start++;;
	}
	else if (str.at(start) == '[')
	{
		result.initialToken(LBRACKET, "");
		start++;;
	}
	else if (str.at(start) == ']')
	{
		result.initialToken(RBRACKET, "");
		start++;;
	}
	else if (str.at(start) == '=')
	{
		result.initialToken(ASSIGN, "");
		start++;;
	}
	else if (str.at(start) == ';')
	{
		result.initialToken(SEMI, "");
		start++;;
	}
	return result;
}

// WHITESPACE를 판별한다
// 별도의 output이 없으므로 start만 1 증가시킨다.
Token isWhiteSpace(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (isspace(str.at(start)))
	{
		result.initialToken(WHITESPACE, "");
		start++;
	}
	return result;
}

// IF, ELSE, WHILE, CLASS, BOOLEAN, RETURN은 VARTYPE과 동일하다
// 단, VARTYPE과 다르게 뒤에 문자, _, $, 숫자가 오는지 체크해야 한다(class는 공백을 체크하면 된다).
Token isIf(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.substr(start, 2) == "if" && start + 2 == str.length())
	{
		result.initialToken(IF, "");
		start += 2;
	}
	else if(str.substr(start, 2) == "if" && !isalpha(str.at(start + 2)) && !isdigit(str.at(start + 2)) && str.at(start+2) != '_' && str.at(start + 2) != '$')
	{
		result.initialToken(IF, "");
		start += 2;
	}
	return result;
}

Token isElse(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.substr(start, 4) == "else" && start + 4 == str.length())
	{
		result.initialToken(ELSE, "");
		start += 4;
	}
	else if (str.substr(start, 4) == "else" && !isalpha(str.at(start + 4)) && !isdigit(str.at(start + 4)) && str.at(start + 4) != '_' && str.at(start + 4) != '$')
	{
		result.initialToken(ELSE, "");
		start += 4;
	}
	return result;
}

Token isWhile(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.substr(start, 5) == "while" && start + 5 == str.length())
	{
		result.initialToken(WHILE, "");
		start += 5;
	}
	else if (str.substr(start, 5) == "while" && !isalpha(str.at(start + 5)) && !isdigit(str.at(start + 5)) && str.at(start + 5) != '_' && str.at(start + 5) != '$')
	{
		result.initialToken(WHILE, "");
		start += 5;
	}
	return result;
}

Token isReturn(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.substr(start, 6) == "return" && start + 6 == str.length())
	{
		result.initialToken(IF, "");
		start += 6;
	}
	else if (str.substr(start, 6) == "return" && !isalpha(str.at(start + 6)) && !isdigit(str.at(start + 6)) && str.at(start + 6) != '_' && str.at(start + 6) != '$')
	{
		result.initialToken(RETURN, "");
		start += 6;
	}
	return result;
}

Token isBoolean(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.substr(start, 5) == "false" && start + 5 == str.length())
	{
		result.initialToken(BOOLEAN, "false");
		start += 5;
	}
	else if (str.substr(start, 5) == "false" && !isalpha(str.at(start + 5)) && !isdigit(str.at(start + 5)) && str.at(start + 5) != '_' && str.at(start + 5) != '$')
	{
		result.initialToken(BOOLEAN, "false");
		start += 5;
	}
	else if (str.substr(start, 4) == "true" && start + 4 == str.length())
	{
		result.initialToken(BOOLEAN, "true");
		start += 4;
	}
	else if (str.substr(start, 4) == "true" && !isalpha(str.at(start + 4)) && !isdigit(str.at(start + 4)) && str.at(start + 4) != '_' && str.at(start + 4) != '$')
	{
		result.initialToken(BOOLEAN, "true");
		start += 4;
	}
	return result;
}

Token isClass(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.substr(start, 5) == "class" && start + 5 == str.length())
	{
		result.initialToken(CLASS, "");
		start += 5;
	}
	else if (str.substr(start, 5) == "class" && isspace(str.at(start + 5)))
	{
		result.initialToken(CLASS, "");
		start += 5;
	}
	return result;
}

Token isArith(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.at(start) == '+')
	{
		result.initialToken(ARITH, "+");
		start++;
	}
	else if (str.at(start) == '-')
	{
		result.initialToken(ARITH, "-");
		start++;;
	}
	else if (str.at(start) == '*')
	{
		result.initialToken(ARITH, "*");
		start++;;
	}
	else if (str.at(start) == '/')
	{
		result.initialToken(ARITH, "/");
		start++;;
	}
	return result;
}

// COMPARE는 앞에 앞의 값이 <, >, !, =인 경우와 그 뒤에 =이 추가로 붙는 경우를 포함한다.
// 뒤에 =가 붙으면 포함하고 start가 2 증가하며, 아닌 경우 start를 1만 증가시킨다.
// !와 =는 무조건 뒤에 =가 붙어야 한다. 
Token isCompare(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.at(start) == '<' || str.at(start) == '>')
	{
		if (start < str.length() - 1 && str.at(start + 1) == '=')
		{
			result.initialToken(COMPARE, str.substr(start, 2));
			start += 2;
		}
		else
		{
			result.initialToken(COMPARE, str.substr(start, 1));
			start ++;
		}
	}
	else if (str.at(start) == '!' || str.at(start) == '=')
	{
		if (str.at(start + 1) == '=')
		{
			result.initialToken(COMPARE, str.substr(start, start + 2));
			start += 2;
		}
	}
	return result;
}

// CHAR는 '<LETTER>' 형태이므로, 이를 만족하는지 판별한다.
Token isChar(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.at(start) == '\'' && isLetter(str.at(start + 1)) && str.at(start + 2) == '\'')
	{
		result.initialToken(CHAR, str.substr(start + 1, 1));
		start += 3;
	}
	return result;
}

// INT는 0, 양수, 음수로 구분된다. 이를 만족하는지 판별한다.
// 앞에 -가 오는 경우, 이것이 음수인지 연산자와 정수의 조합인지 판별해야 한다. 
// 음수가 되는 경우는 1)공백을 제외한 가장 최근에 나온 Token이 ASSIGN이나 COMPARE일 때,
// 2) -가 전체 문자열에서 맨 앞에 있을 때 이다. 이때 공통적으로 -뒤에는 (1~9)(0~9)*의 형태를 가져야 한다.
Token isInt(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	if (str.at(start) == '0')
	{
		result.initialToken(INT, "0");
		start++;
	}
	else if (str.at(start) == '-')
	{
		int reverse = -1;
		int buffer = 0;
		if (start == 0)
		{
			while (isDigit(str.at(start + buffer)))
			{
				buffer++;
				if (buffer + start >= str.length())
					break;
			}
		}
		else
		{
			while (isspace(str.at(start + reverse)))
			{
				reverse--;
				if (start + reverse <= 0)
					break;
			}
			if (str.at(start + reverse) == '<' || str.at(start + reverse) == '>' || str.at(start + reverse) == '=' || 
				str.at(start + reverse) == '+' || str.at(start + reverse) == '-' || str.at(start + reverse) == '*' || str.at(start + reverse) == '/')
			{
				if(isNaturalNum(str.at(start + 1)))
				{
					buffer++;
					while (isDigit(str.at(start + buffer)))
					{
						buffer++;
						if (buffer + start >= str.length())
							break;
					}
					result.initialToken(INT, str.substr(start, buffer));
					start += buffer;
				}
			}
		}
	}
	else if (isNaturalNum(str.at(start)))
	{
		int buffer = 0;
		while (isDigit(str.at(start + buffer)))
		{
			buffer++;
			if (buffer + start >= str.length())
				break;
		}
		result.initialToken(INT, str.substr(start, buffer));
		start += buffer;
	}
	return result;
}

// LITERAL은 "<LETTER>*"의 형태이다.
// "이 처음 등장하면, 닫는 "이 나올때 까지 중간에 있는 LETTER를 모두 받는다.
Token isLiteral(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	int buffer = 1;
	if (str.at(start) == '\"')
	{
		while (true)
		{
			if (str.at(start + buffer) == '\"')
				break;
			buffer++;
		}
		result.initialToken(LITERAL, str.substr(start + 1, buffer - 1));
		start += buffer + 1;
	}
	return result;
}

// JAVA의 변수명은 처음에 _, $, 영문자가 올 수 있다. str(start)가 이에 해당하는지 먼저 체크한다.
// 그리고 그 뒤에 등장하는 모든 영문자, 숫자, _, $를 IDENTIFIER로 받는다.
Token isIdentifier(unsigned int& start, std::string str)
{
	Token result;
	result.initialToken(INVALID, "");
	int buffer = 0;
	if (str.at(start) == '_' || str.at(start) == '$' || isalpha(str.at(start)))
	{
		while (true)
		{
			if (str.at(start + buffer) != '_' && str.at(start + buffer) != '$' && !isdigit(str.at(start + buffer)) && !isalpha(str.at(start + buffer)))
				break;
			buffer++;
			if (buffer + start >= str.length())
				break;
		}
		result.initialToken(IDENTIFIER, str.substr(start, buffer));
		start += buffer;
	}
	return result;
}