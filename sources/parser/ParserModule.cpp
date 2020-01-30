
#include "ParserModule.hpp"
#include "CustomExceptions.hpp"
#include "CommandFactory.hpp"
#include "OperandFactory.hpp"

ParserModule::ParserModule(/* args */)
{
}

ParserModule::~ParserModule()
{
}


Command* ParseTokens(s_LexerLine toParse)
{
	size_t tokenCount = toParse.tokens.size();


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

	if (tokenCount < 2)
		throw UnknownInstructionException();

	std::string param2 = toParse.tokens.at(1);

	if (param1.compare("push") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Push,
			OperandFactory::CreateOperandFromToken(param2));
	if (param1.compare("assert") == 0)
		return CommandFactory::CreateCommand(e_InstructionType::Assert,
			OperandFactory::CreateOperandFromToken(param2));

	throw UnknownInstructionException();
}

Command* ParserModule::ParseLine(s_LexerLine toParse)
{	
	if (toParse.tokens.empty())
		throw LexicalException();
	
	size_t tokenCount = toParse.tokens.size();
	if (tokenCount >= 1)
		return ParseTokens(toParse);

	throw UnknownInstructionException();
}



int8_t   ParserModule::ParseInt8_t(std::string param)
{
	size_t i = 0;
	while (i < param.size())
	{
		if (param.at(i) == '(')
		{
			if (i + 1 >= param.size())
				throw LexicalException();
			i++;

			long long tempVal = atoll(param.c_str() + i);
			if (tempVal < -128)
				throw UnderflowException();
			if (tempVal > 127)
				throw OverflowException();
		
			return static_cast<int8_t>(tempVal);
		}
		i++;
	}
	throw OperandNotSpecifiedException();
}

int16_t  ParserModule::ParseInt16_t(std::string param)
{
	size_t i = 0;
	while (i < param.size())
	{
		if (param.at(i) == '(')
		{
			if (i + 1 >= param.size())
				throw LexicalException();
			i++;

			long long tempVal = atoll(param.c_str() + i);
			if (tempVal < -32768)
				throw UnderflowException();
			if (tempVal > 32767)
				throw OverflowException();
		
			return static_cast<int16_t>(tempVal);
		}
		i++;
	}
	throw OperandNotSpecifiedException();
}

int32_t  ParserModule::ParseInt32_t(std::string param)
{
	size_t i = 0;
	while (i < param.size())
	{
		if (param.at(i) == '(')
		{
			if (i + 1 >= param.size())
				throw LexicalException();
			i++;

			long long tempVal = atoll(param.c_str() + i);
			if (tempVal < -2147483648)
				throw UnderflowException();
			if (tempVal > 2147483647)
				throw OverflowException();
		
			return static_cast<int32_t>(tempVal);
		}
		i++;
	}
	throw OperandNotSpecifiedException();
}




float    ParserModule::ParseFloat(std::string param)
{
	size_t i = 0;
	while (i < param.size())
	{
		if (param.at(i) == '(')
		{
			if (i + 1 >= param.size())
				throw LexicalException();
			i++;


			float tempVal = static_cast<float>((atof(param.c_str() + i)));
			if (isnan(tempVal))
				throw LexicalException();
			if (isinf(tempVal))
				throw OverflowException();
			return tempVal;
		}
		i++;
	}
	throw OperandNotSpecifiedException();
}

double   ParserModule::ParseDouble(std::string param)
{
	size_t i = 0;
	while (i < param.size())
	{
		if (param.at(i) == '(')
		{
			if (i + 1 >= param.size())
				throw LexicalException();
			i++;

			double tempVal = atof(param.c_str() + i);
			if (isnan(tempVal))
				throw LexicalException();
			if (isinf(tempVal))
				throw OverflowException();
			return tempVal;
		}
		i++;
	}
	throw OperandNotSpecifiedException();
}
