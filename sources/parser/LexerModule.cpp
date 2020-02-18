
#include "LexerModule.hpp"

LexerModule::LexerModule(/* args */)
{
}

LexerModule::~LexerModule()
{
}

void 	LexerModule::ShowScannedData(const std::vector<s_LexerLine> &lines)
{
	std::cout << "\x1b[32m" << "Lexer Scanned Data\n" << "\x1b[0m" << std::endl;
	for (int i = 0; i < (int)lines.size(); i++)
	{
		// Line
		std::cout << " Line " << i + 1 << ":\t" << "|\x1b[36m" << lines.at(i).line << "\x1b[0m|" << "\n";
		// Tokens:
		std::cout << " Tokens:\t";
		if (lines.at(i).tokens.empty())
			std::cout << " Empty";
		for (int iTok = 0; iTok < (int)lines.at(i).tokens.size(); iTok++)
		{
			std::cout << "|\x1b[31m" << lines.at(i).tokens.at(iTok) << "\x1b[0m|"; 
		}
		std::cout << std::endl;
	}
}



bool IsSpace(char ch)
{
	if (ch < 33 || ch > 126)
		return true;
	return false;
}

std::vector<std::string> LexerModule::SeparateWords(std::string line)
{
	std::vector<std::string> result;

	size_t start = 0;
	size_t end = 0;
	size_t i = 0;
	while (i < line.size())
	{
		// Search for word
		if (!IsSpace(line[i]))
		{// Found word
			start = i;
			end = i;
			while (end < line.size())
			{ //Search when word ends
				if (IsSpace(line[end]))
				{// Found word ending
					break;
				}
				end++;
			}
			result.push_back(line.substr(start, end - start));
			// Skiping to found Space
			i = end;
		}
		i++;
	}
	return result;
}

std::vector<s_LexerLine>	LexerModule::SetupNewLines(const std::vector<std::string> &parsedLines)
												// std::vector<s_LexerLine> &newLines)
{
	std::vector<s_LexerLine> newLines;
	for (int i = 0; i < (int)parsedLines.size(); i++)
	{
		s_LexerLine tempStruct;

		tempStruct.line = parsedLines.at(i);
		// std::cout << parsedLines.at(i);
		tempStruct.tokens = SeparateWords(tempStruct.line);
		newLines.push_back(tempStruct);
	}

	// ShowScannedData(newLines);
	ClearLines(newLines);
	// ShowScannedData(newLines);
	return newLines;
}

void 	LexerModule::ClearLines(std::vector<s_LexerLine> &lines)
{
	std::vector<s_LexerLine> clearedResult;

	for (size_t i = 0; i < lines.size(); i++)
	{
		if (!lines[i].tokens.empty())
		{// Empty tokens check
			std::string str = lines[i].tokens.at(0);
			if (str.size() >= 1)
			{// Comment check
				if (str[0] == ';')
					continue;
			}
			clearedResult.push_back(lines[i]);
		}
	}
	lines.clear();
	lines = clearedResult;
}