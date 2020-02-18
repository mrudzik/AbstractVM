
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
public:
    LexerModule(/* args */);
    ~LexerModule();

	static std::vector<s_LexerLine> SetupNewLines(	const std::vector<std::string> &parsedLines);
								// std::vector<s_LexerLine> &newLines);
	static void ClearLines(std::vector<s_LexerLine> &lines);
	static void ShowScannedData(const std::vector<s_LexerLine> &lines);
	static std::vector<std::string> SeparateWords(std::string line);

};

#endif