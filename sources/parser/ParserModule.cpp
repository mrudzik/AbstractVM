
#include "ParserModule.hpp"
#include "CustomExceptions.hpp"

ParserModule::ParserModule(/* args */)
{
}

ParserModule::~ParserModule()
{
}


Command* ParserModule::ParseLine(s_LexerLine toParse)
{
	(void) toParse;
	throw UnknownInstructionException();
}
