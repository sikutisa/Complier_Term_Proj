#ifndef DFA_H_
#define DFA_H_

#include "token.h"

// dfa���� �־��� ���ڰ�(�Ǵ� ���ڿ�)�� � Token���� �Ǻ��� �� �ִ� �Լ����� �����Ǿ� �ִ�.
// �� �Լ����� �Ǻ��ϰ��� �ϴ� Token�� dfa�� �������� �����Ѵ�.
bool isLetter(char c);
bool isNaturalNum(char c);
bool isDigit(char c);


Token isVarType(unsigned int& start, std::string str);
Token isExtraToken(unsigned int& start, std::string str);
Token isWhiteSpace(unsigned int& start, std::string str);
Token isIf(unsigned int& start, std::string str);
Token isElse(unsigned int& start, std::string str);
Token isWhile(unsigned int& start, std::string str);
Token isReturn(unsigned int& start, std::string str);
Token isBoolean(unsigned int& start, std::string str);
Token isClass(unsigned int& start, std::string str);
Token isArith(unsigned int& start, std::string str);
Token isCompare(unsigned int& start, std::string str);
Token isChar(unsigned int& start, std::string str);
Token isInt(unsigned int& start, std::string str);
Token isLiteral(unsigned int& start, std::string str);
Token isIdentifier(unsigned int& start, std::string str);

#endif // !DFA_H_