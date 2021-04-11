#include "dfa.h"

// dfa�� ���� �־��� ���ڿ��� �м��Ѵ�
// Ž���ϰ��� �ϴ� Token�� ��ġ�ϸ� �ش� Token ���� ��ŭ start�� �̵����� �ش�.
// �ٸ� Token�̶��, �̵���Ű�� �ʴ´�.

// CHAR�� �����ϱ� ���� LETTER �Ǻ���
bool isLetter(char c)
{
	if (isalpha(c) || isdigit(c) || c == ' ')
		return true;
	return false;
}

//INT�� �����ϱ� ���� DIGIT�� NATURALNUM
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

// VARTYPE�� int, char, String, Boolean�� �� �� ������ IDENTIFIER�� �����ϱ� ���� �ڿ� whitespace�� �ִ��� üũ�ؾ� �Ѵ�.
// VARTYPE�� �־��� ���, �ڸ� ������ �� ���� ������, �Էµ� ���ڿ��� ���̿� ���� ó���� ���ش�.
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

// ������ ����� 1�� Token�� �Ǻ��Ѵ�
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

// WHITESPACE�� �Ǻ��Ѵ�
// ������ output�� �����Ƿ� start�� 1 ������Ų��.
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

// IF, ELSE, WHILE, CLASS, BOOLEAN, RETURN�� VARTYPE�� �����ϴ�
// ��, VARTYPE�� �ٸ��� �ڿ� ����, _, $, ���ڰ� ������ üũ�ؾ� �Ѵ�(class�� ������ üũ�ϸ� �ȴ�).
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

// COMPARE�� �տ� ���� ���� <, >, !, =�� ���� �� �ڿ� =�� �߰��� �ٴ� ��츦 �����Ѵ�.
// �ڿ� =�� ������ �����ϰ� start�� 2 �����ϸ�, �ƴ� ��� start�� 1�� ������Ų��.
// !�� =�� ������ �ڿ� =�� �پ�� �Ѵ�. 
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

// CHAR�� '<LETTER>' �����̹Ƿ�, �̸� �����ϴ��� �Ǻ��Ѵ�.
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

// INT�� 0, ���, ������ ���еȴ�. �̸� �����ϴ��� �Ǻ��Ѵ�.
// �տ� -�� ���� ���, �̰��� �������� �����ڿ� ������ �������� �Ǻ��ؾ� �Ѵ�. 
// ������ �Ǵ� ���� 1)������ ������ ���� �ֱٿ� ���� Token�� ASSIGN�̳� COMPARE�� ��,
// 2) -�� ��ü ���ڿ����� �� �տ� ���� �� �̴�. �̶� ���������� -�ڿ��� (1~9)(0~9)*�� ���¸� ������ �Ѵ�.
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

// LITERAL�� "<LETTER>*"�� �����̴�.
// "�� ó�� �����ϸ�, �ݴ� "�� ���ö� ���� �߰��� �ִ� LETTER�� ��� �޴´�.
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

// JAVA�� �������� ó���� _, $, �����ڰ� �� �� �ִ�. str(start)�� �̿� �ش��ϴ��� ���� üũ�Ѵ�.
// �׸��� �� �ڿ� �����ϴ� ��� ������, ����, _, $�� IDENTIFIER�� �޴´�.
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