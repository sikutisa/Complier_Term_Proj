#ifndef SYNTAX_ANALYZER_H
#define SYNTAX_ANALYZER_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <map>

void makeInputFormat(std::string& temp, std::queue<std::pair<std::string, std::string>>& input);
#endif // !SYNTAX_ANALYZER_H

std::map<std::string, int> actionHashMap =
{
	{"vtype", 0},
	{"id", 1},
	{"semi", 2},
	{"assign", 3},
	{"literal", 4},
	{"character", 5},
	{"boolstr", 6},
	{"addsub", 7},
	{"muldiv", 8},
	{"lparen", 9},
	{"rparen", 10},
	{"num", 11},
	{"lbrace", 12},
	{"rbrace", 13},
	{"comma", 14},
	{"if", 15},
	{"while", 16},
	{"comp", 17},
	{"else", 18},
	{"return", 19},
	{"class", 20},
	{"$", 21}
};

std::map<std::string, int> gotoHashMap =
{
	{"CODE", 0},
	{"VDECL", 1},
	{"ASSIGN", 2},
	{"RHS", 3},
	{"EXPR", 4},
	{"T", 5},
	{"F", 6},
	{"FDECL", 7},
	{"ARG", 8},
	{"MOREARGS", 9},
	{"BLOCK", 10},
	{"STMT", 11},
	{"COND", 12},
	{"P", 13},
	{"ELSE", 14},
	{"RETURN", 15},
	{"CDECL", 16},
	{"ODECL", 17}
};