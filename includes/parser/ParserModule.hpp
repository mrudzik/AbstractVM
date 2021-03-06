
#ifndef PARSER_MODULE_HPP
#define PARSER_MODULE_HPP

#include "Command.hpp"
#include "LexerModule.hpp"
#include <cmath>

class ParserModule
{
public:
    ParserModule(/* args */);
    ~ParserModule();

	static Command* ParseLine(s_LexerLine toParse);

	static void 	LexicCheckInt(std::string param);
	static void 	LexicCheckFloat(std::string param);
	

    static int8_t   ParseInt8_t(std::string param);
    static int16_t  ParseInt16_t(std::string param);
    static int32_t  ParseInt32_t(std::string param);
    static float    ParseFloat(std::string param);
    static double   ParseDouble(std::string param);
};

#endif