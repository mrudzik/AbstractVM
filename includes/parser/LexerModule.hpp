
#ifndef LEXER_MODULE_HPP
#define LEXER_MODULE_HPP

#include <string>
#include <vector>
#include <iostream>

struct s_lexerLine
{
    std::string                 line;
    std::vector<std::string>    tokens;
};


class LexerModule
{
private:
    std::vector<s_lexerLine>	_lexedLines;





public:
    LexerModule(/* args */);
    ~LexerModule();

	void SetupNewLines(std::vector<std::string> lines);
	void ShowScannedData();

	std::vector<std::string> SeparateWords(std::string line);

};

#endif