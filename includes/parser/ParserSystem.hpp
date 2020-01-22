
#ifndef PARSER_SYSTEM_HPP
#define PARSER_SYSTEM_HPP

#include "LexerModule.hpp"
#include "ParserModule.hpp"

#include <iostream>
#include <vector>
#include <string>
#include <memory>

class ParserSystem
{
private:
    LexerModule*	lexerMod;
    ParserModule*	parserMod;

	std::vector<std::string> 	ReadFileLines(std::string path);

public:
    ParserSystem(/* args */);
    ~ParserSystem();

    // Used when reading program from a file
    void ParseInputFile(std::string path);
    // Used when typing program in manual mode
    void ParseInputLine(std::string line);

};




#endif