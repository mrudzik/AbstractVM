
#include "OperandFactory.hpp"
#include "CustomExceptions.hpp"

OperandFactory::OperandFactory(/* args */)
{
}

OperandFactory::~OperandFactory()
{
}


IOperand* OperandFactory::CreateOperandFromToken(std::string token)
{
	if (token.compare("int8(") > 0)
		return CreateInt8(8);
	if (token.compare("int16(") > 0)
		return CreateInt16(16);
	if (token.compare("int32(") > 0)
		return CreateInt32(32);
	if (token.compare("float(") > 0)
		return CreateFloat(123.0f);
	if (token.compare("double(") > 0)
		return CreateDouble(123.0);


	throw UnknownOperandException();
}


IOperand* OperandFactory::CreateInt8(int8_t value)
{
	
}

IOperand* OperandFactory::CreateInt16(int16_t value)
{

}

IOperand* OperandFactory::CreateInt32(int32_t value)
{

}

IOperand* OperandFactory::CreateFloat(float value)
{

}

IOperand* OperandFactory::CreateDouble(double value)
{

}
