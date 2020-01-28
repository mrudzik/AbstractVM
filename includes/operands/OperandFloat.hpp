#ifndef OPERAND_FLOAT_HPP
#define OPERAND_FLOAT_HPP

#include "IOperand.hpp"

class OperandFloat : public IOperand
{
private:
	float _value;
public:
	OperandFloat(float value);
	~OperandFloat();

	virtual e_OperandType OperandDouble::getType();
};


#endif