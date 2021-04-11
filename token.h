#ifndef TOKEN_H_
#define TOKEN_H_

#include <string>
#include <vector>

// TokenÀÇ Á¾·ù
enum TYPE_OF_TOKEN
{
	VARTYPE, BOOLEAN, IF, ELSE, WHILE, CLASS, RETURN,
	LBRACE, RBRACE, LPAREN, RPAREN, LBRACKET, RBRACKET,
	COMMA, WHITESPACE, SEMI,
	COMPARE, ARITH, ASSIGN,
	NATUALNUM, DIGIT, INT,
	ALPHABET, LETTER, CHAR, LITERAL, IDENTIFIER,
	INVALID
};

class Token
{
public:
	TYPE_OF_TOKEN tokenType = INVALID;
	std::string tokenVal;
	std::string tokenTypeName;
	void initialToken(const TYPE_OF_TOKEN a, const std::string b);
};
#endif