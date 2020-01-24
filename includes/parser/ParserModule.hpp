
#ifndef PARSER_MODULE_HPP
#define PARSER_MODULE_HPP

#include "Command.hpp"
#include "LexerModule.hpp"

class ParserModule
{
private:
    /* data */
public:
    ParserModule(/* args */);
    ~ParserModule();

	Command* ParseLine(s_LexerLine toParse);

};

#endif