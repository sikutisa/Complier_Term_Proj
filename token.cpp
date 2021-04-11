#include "token.h"

// Token Ŭ���� ��ü�� �ʱ�ȭ �� �� �� Token ���� �̸�
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

// Token class ��ü�� �ʱ�ȭ
void Token::initialToken(const TYPE_OF_TOKEN a, const std::string b)
{
	this->tokenType = a;
	this->tokenTypeName = tokenName[a];
	this->tokenVal = b;
}