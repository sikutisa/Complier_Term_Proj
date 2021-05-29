#ifndef SYNTAX_ANALYZER_H
#define SYNTAX_ANALYZER_H

#include <iostream>
#include <fstream>
#include <stack>
#include <queue>
#include <map>
#include <deque>

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
	{"S", 0},
	{"CODE", 1},
	{"VDECL", 2},
	{"ASSIGN", 3},
	{"RHS", 4},
	{"EXPR", 5},
	{"T", 6},
	{"F", 7},
	{"FDECL", 8},
	{"ARG", 9},
	{"MOREARGS", 10},
	{"BLOCK", 11},
	{"STMT", 12},
	{"COND", 13},
	{"P", 14},
	{"ELSE", 15},
	{"RETURN", 16},
	{"CDECL", 17},
	{"ODECL", 18}
};