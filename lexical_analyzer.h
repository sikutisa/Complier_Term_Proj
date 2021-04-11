#ifndef LEXICAL_ANALYZER_H_
#define LEXICAL_ANALYZER_H_

#include <iostream>
#include <fstream>
#include "dfa.h"

std::vector<Token> outputTokenArr;
void lexicalAnalyze(unsigned int start, const std::string str);

#endif