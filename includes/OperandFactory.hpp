
#ifndef OPERAND_FACTORY_HPP
#define OPERAND_FACTORY_HPP

#include "IOperand.hpp"


class OperandFactory
{
private:
	/* data */
public:
	OperandFactory(/* args */);
	~OperandFactory();

	IOperand* CreateOperandFromToken(std::string token);
	IOperand* CreateInt8(int8_t value);
	IOperand* CreateInt16(int16_t value);
	IOperand* CreateInt32(int32_t value);
	IOperand* CreateFloat(float value);
	IOperand* CreateDouble(double value);
	
};

#endif