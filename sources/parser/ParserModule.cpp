
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
	static int i = 0;

	i++;
	switch (i)
	{
	case 1:
		throw DivModZeroException();
	case 2:
		throw FalseAssertException();
	case 3:
		throw InstructionPopEmptyException();
	case 4:
		throw LexicalException();
	case 5:
		throw MathEmptyStackException();
	case 6:
		throw NoExitException();
	case 7:
		throw OverflowException();
	case 8:
		throw UnderflowException();
	case 9:
		throw UnknownInstructionException();
	default:
		break;
	}

	throw NoExitException();

}
