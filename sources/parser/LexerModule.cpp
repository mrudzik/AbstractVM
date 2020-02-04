
#include "LexerModule.hpp"

LexerModule::LexerModule(/* args */)
{
}

LexerModule::~LexerModule()
{
}

void 	LexerModule::ShowScannedData()
{
	std::cout << "\x1b[32m" << "Lexer Scanned Data\n" << "\x1b[0m" << std::endl;
	for (int i = 0; i < (int)_lexedLines.size(); i++)
	{
		// Line
		std::cout << " Line " << i + 1 << ":\t" << "|\x1b[36m" << _lexedLines.at(i).line << "\x1b[0m|" << "\n";
		// Tokens:
		std::cout << " Tokens:\t";
		if (_lexedLines.at(i).tokens.empty())
			std::cout << " Empty";
		for (int iTok = 0; iTok < (int)_lexedLines.at(i).tokens.size(); iTok++)
		{
			std::cout << "|\x1b[31m" << _lexedLines.at(i).tokens.at(iTok) << "\x1b[0m|"; 
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

void 	LexerModule::SetupNewLines(std::vector<std::string> lines)
{
	_lexedLines.clear();
	for (int i = 0; i < (int)lines.size(); i++)
	{
		s_LexerLine tempStruct;

		tempStruct.line = lines.at(i);
		tempStruct.tokens = SeparateWords(tempStruct.line);
		_lexedLines.push_back(tempStruct);
	}

	ClearEmptyLines();
	ShowScannedData();
}

void 	LexerModule::ClearEmptyLines()
{
	std::vector<s_LexerLine> clearedResult;

	size_t i = 0;
	while (i < _lexedLines.size())
	{
		if (!_lexedLines[i].tokens.empty())
		{// If not empty push to result
			clearedResult.push_back(_lexedLines[i]);
		}
		i++;
	}
	_lexedLines.clear();
	_lexedLines = clearedResult;
}







size_t 	LexerModule::GetLexedSize()
{
	return _lexedLines.size();
}

s_LexerLine LexerModule::GetLexedLine(int lineNum)
{
	return _lexedLines.at(lineNum);
}