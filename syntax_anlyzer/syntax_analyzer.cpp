#include "slr_table.h"
#include "syntax_analyzer.h"

int main(int argc, char* argv[])
{
	std::ifstream readTXT;
	readTXT.open(argv[1]);

	std::cout << '1' << '\n';
	if (readTXT.is_open())
	{
		std::cout << '2' << '\n';
		while (!readTXT.eof())
		{
			std::string input;
			getline(readTXT, input);
			std::cout << input << '\n';
		}
		readTXT.close();
	}
	std::cout << '3' << '\n';
	readTXT.close();
	return 0;
}