#ifndef DFA_H_
#define DFA_H_

#include "token.h"

// dfa에는 주어진 문자가(또는 문자열)이 어떤 Token인지 판별할 수 있는 함수들이 구현되어 있다.
// 각 함수들은 판별하고자 하는 Token의 dfa를 바탕으로 동작한다.
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