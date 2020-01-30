
#include "OperandFactory.hpp"
#include "CustomExceptions.hpp"
#include "ParserModule.hpp"



OperandFactory::OperandFactory(/* args */)
{
}

OperandFactory::~OperandFactory()
{
}


IOperand* OperandFactory::CreateOperandFromToken(std::string token)
{
	if (token.compare(0, 5, "int8(") == 0)
		return CreateInt8(ParserModule::ParseInt8_t(token));
	if (token.compare(0, 6, "int16(") == 0)
		return CreateInt16(ParserModule::ParseInt16_t(token));
	if (token.compare(0, 6, "int32(") == 0)
		return CreateInt32(ParserModule::ParseInt32_t(token));
	if (token.compare(0, 6, "float(") == 0)
		return CreateFloat(ParserModule::ParseFloat(token));
	if (token.compare(0, 7, "double(") == 0)
		return CreateDouble(ParserModule::ParseDouble(token));


	throw UnknownOperandException();
}


IOperand* OperandFactory::CreateInt8(int8_t value)
{
	return new OperandTemplate<int8_t>(value, e_OperandType::Int8);
}

IOperand* OperandFactory::CreateInt16(int16_t value)
{
	return new OperandTemplate<int16_t>(value, e_OperandType::Int16);
}

IOperand* OperandFactory::CreateInt32(int32_t value)
{
	return new OperandTemplate<int32_t>(value, e_OperandType::Int32);
}

IOperand* OperandFactory::CreateFloat(float value)
{
	return new OperandTemplate<float>(value, e_OperandType::Float);
}

IOperand* OperandFactory::CreateDouble(double value)
{
	return new OperandTemplate<double>(value, e_OperandType::Double);
}
