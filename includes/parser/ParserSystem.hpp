
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
	static std::vector<std::string> ReadFileLines(std::string path);
	static std::vector<Command*> ParseLinesToCommands(std::vector<s_LexerLine> &parsedData);
    static void ParsingProcedure(std::vector<s_LexerLine> &parsedData);
    static void ClearCommands(std::vector<Command*> &commVec);

public:
    ParserSystem();
    ~ParserSystem();

    // Used when reading program from a file
    static void ParseInputFile(std::string path);
    // Used when typing program in manual mode
    static void ParseInputManual();

    static void ParseInputLine(std::string line);

   

};




#endif