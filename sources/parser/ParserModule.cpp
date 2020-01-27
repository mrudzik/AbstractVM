
#include "ParserModule.hpp"
#include "CustomExceptions.hpp"
#include "CommandFactory.hpp"

ParserModule::ParserModule(/* args */)
{
}

ParserModule::~ParserModule()
{
}


Command* ParseSingleParameter(s_LexerLine toParse)
{
	std::string param1 = toParse.tokens.at(0);

	if (param1.compare("pop") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Pop, NULL);
	if (param1.compare("dump") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Dump, NULL);
	if (param1.compare("add") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Add, NULL);
	if (param1.compare("sub") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Sub, NULL);
	if (param1.compare("mul") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Mul, NULL);
	if (param1.compare("div") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Div, NULL);
	if (param1.compare("mod") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Mod, NULL);
	if (param1.compare("print") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Print, NULL);
	if (param1.compare("exit") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Exit, NULL);

	throw UnknownInstructionException();
}

Command* ParseDoubleParameter(s_LexerLine toParse)
{
	std::string param1 = toParse.tokens.at(0);
	std::string param2 = toParse.tokens.at(1);

	if (param1.compare("push") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Push, NULL);
	if (param1.compare("assert") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Assert, NULL);

	throw UnknownInstructionException();
}

Command* ParserModule::ParseLine(s_LexerLine toParse)
{	
	if (toParse.tokens.empty())
		throw LexicalException();
	
	size_t tokenCount = toParse.tokens.size();
	if (tokenCount == 1)
		return ParseSingleParameter(toParse);
	if (tokenCount == 2) // Find Instructions with values
		return ParseDoubleParameter(toParse);

	throw UnknownInstructionException();
}
