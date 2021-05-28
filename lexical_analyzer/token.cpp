#include "token.h"

// Token 클래스 객체를 초기화 할 때 쓸 Token 종류 이름
std::vector<std::string> tokenName
{
	"VARTYPE", "BOOLEAN", "IF", "ELSE", "WHILE", "CLASS", "RETURN",
	"LBRACE", "RBRACE", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET",
	"COMMA", "WHITESPACE", "SEMI",
	"COMPARE", "ARITH", "ASSIGN",
	"NATUALNUM", "DIGIT", "INT",
	"ALPHABET", "LETTER", "CHAR", "LITERAL", "IDENTIFIER",
	"INVALID"
};

// Token class 객체를 초기화
void Token::initialToken(const TYPE_OF_TOKEN a, const std::string b)
{
	this->tokenType = a;
	this->tokenTypeName = tokenName[a];
	this->tokenVal = b;
}