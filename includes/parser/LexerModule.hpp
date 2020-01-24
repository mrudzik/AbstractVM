
#ifndef LEXER_MODULE_HPP
#define LEXER_MODULE_HPP

#include <string>
#include <vector>
#include <iostream>

struct s_LexerLine
{
    std::string                 line;
    std::vector<std::string>    tokens;
};


class LexerModule
{
private:
    std::vector<s_LexerLine>	_lexedLines;

public:
    LexerModule(/* args */);
    ~LexerModule();

	void SetupNewLines(std::vector<std::string> lines);
	void ClearEmptyLines();
	void ShowScannedData();
	
	std::vector<std::string> SeparateWords(std::string line);

	size_t GetLexedSize();
	s_LexerLine GetLexedLine(int lineNum);


};

#endif