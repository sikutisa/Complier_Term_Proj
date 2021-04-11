#include "lexical_analyzer.h"

int main(int argc, char* argv[])
{
	std::ifstream readTXT;
	std::string inputFileName = argv[1];
	readTXT.open(inputFileName);

	// JAVA �ڵ带 �Է� �ް�, lexical analyze�� �Ѵ�.
	// �� ����� outputTokenArr�� �ִ´�.
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

	// outputTokenArr�� �տ������� analyze�� ����� output.txt�� ����Ѵ�.
	// ���� Token�� value�� �ִٸ� value�� ���� ����ϰ�, �ƴ϶�� Type�� ����Ѵ�.
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

// dfa�� ���� �ڵ带 �м��ϰ� �� ����� outputTokenarr�� �ִ´�
// start�� �Է¹��� ��ü ���ڿ� �� ��𼭺��� �м��� �����ؾ��ϴ��� ����Ѵ�. 
// ���� Token�� ��Ȯ�� ã�Ƴ�����, �� Token�� �����ϴ� ���̸�ŭ start�� �̵��ϰ�, �ƴ� ��� �̵����� �ʴ´�.
// dfa.cpp���� ������ �Լ����� �������� �����ϸ�, Token�� �ȿ��� �켱������ ó���ؾ� �ϴ� ���(e.g. VARTYPE�� IDENTIFIER���� ���� ó��)���� ó���ϵ��� �Ѵ�.
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
		} // ������� ���� �ʿ䰡 ����
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