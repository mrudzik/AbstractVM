#ifndef OPERAND_FLOAT_HPP
#define OPERAND_FLOAT_HPP

#include "IOperand.hpp"

class OperandFloat : public IOperand
{
	public:
// private:
	float _value;
// public:
	OperandFloat(float value);
	~OperandFloat();

	virtual e_OperandType getType() const
	{
		return e_OperandType::Float;
	}
};


#endif