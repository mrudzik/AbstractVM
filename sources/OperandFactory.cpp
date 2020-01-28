
#include "OperandFactory.hpp"
#include "CustomExceptions.hpp"
#include "ParserModule.hpp"


OperandFactory::OperandFactory(/* args */)
{
}

OperandFactory::~OperandFactory()
{
}


static IOperand* OperandFactory::CreateOperandFromToken(std::string token)
{
	if (token.compare("int8(") > 0)
		return CreateInt8(ParserModule::ParseInt8(token));
	if (token.compare("int16(") > 0)
		return CreateInt16(ParserModule::ParseInt16(token));
	if (token.compare("int32(") > 0)
		return CreateInt32(ParserModule::ParseInt32(token));
	if (token.compare("float(") > 0)
		return CreateFloat(ParserModule::ParseFloat(token));
	if (token.compare("double(") > 0)
		return CreateDouble(ParserModule::ParseDouble(token));


	throw UnknownOperandException();
}


static IOperand* OperandFactory::CreateInt8(int8_t value)
{
	return new OperandInt8(value);
}

static IOperand* OperandFactory::CreateInt16(int16_t value)
{
	return new OperandInt16(value);
}

static IOperand* OperandFactory::CreateInt32(int32_t value)
{
	return new OperandInt32(value);
}

static IOperand* OperandFactory::CreateFloat(float value)
{
	return new OperandFloat(value);
}

static IOperand* OperandFactory::CreateDouble(double value)
{
	return new OperandDouble(value);
}
