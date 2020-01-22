
#include "LexerModule.hpp"

LexerModule::LexerModule(/* args */)
{
}

LexerModule::~LexerModule()
{
}


void 	LexerModule::ShowScannedData()
{
	std::cout << "\x1b[32m" << "Scanned Data\n" << "\x1b[0m" << std::endl;
	for (int i = 0; i < (int)_lexedLines.size(); i++)
	{
		std::cout << i + 1 << ":\t" << "\x1b[36m" << _lexedLines.at(i).line << "\x1b[0m" << std::endl;
	}
}



int FindNextWordPos(std::string line, int pos)
{
	for (int i = pos; i < (int)line.size(); i++)
	{
		if (!isspace(line[i]))
			return i;
	}
	return (int)line.size() - 1;
}


std::vector<std::string> LexerModule::SeparateWords(std::string line)
{
	std::vector<std::string> result;

	size_t start = 0;
	size_t pos = 0;
	std::string token;

	while (pos < line.size())
	{
		if (isspace(line[pos]))
		{
			token = line.substr(start, pos);
			start = FindNextWordPos(line, pos);
			pos = start;
			// line.erase(0, FindNextWordPos(line, (int)pos));
				//pos + delimiter.length());
			result.push_back(token);
		}
		pos++;
	}
	// result.push_back(line);
	
	std::cout << "Tokens:_";
	for (int i = 0; i < (int)result.size(); i++)
	{
		std::cout << "_|" << i << ":_" << result.at(i); 
	}

	std::cout << std::endl;
	return result;
}


void 	LexerModule::SetupNewLines(std::vector<std::string> lines)
{
	_lexedLines.clear();
	for (int i = 0; i < (int)lines.size(); i++)
	{
		s_lexerLine tempStruct;

		tempStruct.line = lines.at(i);
		tempStruct.tokens = SeparateWords(tempStruct.line);
		_lexedLines.push_back(tempStruct);
	}
}
