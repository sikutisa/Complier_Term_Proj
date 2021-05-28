#include "lexical_analyzer.h"

int main(int argc, char* argv[])
{
	std::ifstream readTXT;
	std::string inputFileName = argv[1];
	readTXT.open(inputFileName);

	// JAVA 코드를 입력 받고, lexical analyze를 한다.
	// 그 결과를 outputTokenArr에 넣는다.
	if (readTXT.is_open())
	{
		unsigned int startPoint = 0;
		while (!readTXT.eof())
		{
			std::string input;
			getline(readTXT, input);
			lexicalAnalyze(startPoint, input);
		}
		readTXT.close();
	}

	std::ofstream writeTXT;
	inputFileName = inputFileName.substr(0, inputFileName.size() - 4);
	inputFileName += "_output.txt";
	writeTXT.open(inputFileName);

	// outputTokenArr의 앞에서부터 analyze한 결과를 output.txt에 기록한다.
	// 만약 Token이 value가 있다면 value를 같이 기록하고, 아니라면 Type만 기록한다.
	if (writeTXT.is_open())
	{
		for (int i = 0; i < outputTokenArr.size(); i++)
		{
			if (outputTokenArr.at(i).tokenVal.empty())
			{
				writeTXT.write("<", 1);
				writeTXT.write(outputTokenArr.at(i).tokenTypeName.c_str(), outputTokenArr.at(i).tokenTypeName.size());
				writeTXT.write(">", 1);
			}
			else
			{
				writeTXT.write("<", 1);
				writeTXT.write(outputTokenArr.at(i).tokenTypeName.c_str(), outputTokenArr.at(i).tokenTypeName.size());
				writeTXT.write(", ", 2);
				writeTXT.write(outputTokenArr.at(i).tokenVal.c_str(), outputTokenArr.at(i).tokenVal.size());
				writeTXT.write(">", 1);
			}
			writeTXT.write("\n", 1);
		}
		writeTXT.close();
	}
	return 0;
}

// dfa에 따라 코드를 분석하고 그 결과를 outputTokenarr에 넣는다
// start는 입력받은 전체 문자열 중 어디서부터 분석을 시작해야하는지 기록한다. 
// 만약 Token을 정확히 찾아냈으면, 그 Token이 차지하는 길이만큼 start가 이동하고, 아닐 경우 이동하지 않는다.
// dfa.cpp에서 구현한 함수들을 바탕으로 동작하며, Token들 안에서 우선적으로 처리해야 하는 경우(e.g. VARTYPE을 IDENTIFIER보다 먼저 처리)부터 처리하도록 한다.
void lexicalAnalyze(unsigned int start, const std::string str)
{
	Token tokenBuffer;
	unsigned int temp1;
	unsigned int temp2;
	while (true)
	{
		temp1 = temp2 = start;
		if (isWhiteSpace(start, str).tokenType == WHITESPACE) 
		{
			temp1++; temp2++;
			if (start >= str.length()) { break; }
		} // 결과값에 넣을 필요가 없다
		else if (isVarType(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isVarType(temp1, str).tokenType, isVarType(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isExtraToken(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isExtraToken(temp1, str).tokenType, isExtraToken(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isIf(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isIf(temp1, str).tokenType, isIf(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isElse(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isElse(temp1, str).tokenType, isElse(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isWhile(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isWhile(temp1, str).tokenType, isWhile(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isReturn(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isReturn(temp1, str).tokenType, isReturn(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isBoolean(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isBoolean(temp1, str).tokenType, isBoolean(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isClass(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isClass(temp1, str).tokenType, isClass(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isCompare(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isCompare(temp1, str).tokenType, isCompare(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isChar(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isChar(temp1, str).tokenType, isChar(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isLiteral(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isLiteral(temp1, str).tokenType, isLiteral(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isInt(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isInt(temp1, str).tokenType, isInt(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isArith(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isArith(temp1, str).tokenType, isArith(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
		else if (isIdentifier(start, str).tokenType != INVALID)
		{
			tokenBuffer.initialToken(isIdentifier(temp1, str).tokenType, isIdentifier(temp2, str).tokenVal);
			outputTokenArr.push_back(tokenBuffer);
			if (start >= str.length()) { break; }
		}
	}
}