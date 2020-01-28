
#ifndef OPERAND_INT8_HPP
#define OPERAND_INT8_HPP

#include "IOperand.hpp"

class OperandInt8 : public IOperand
{
	public:
// private:
	int8_t _value;

// public:
	OperandInt8(int8_t value);
	~OperandInt8();

	virtual e_OperandType getType() const
	{
		return e_OperandType::Int8;
	}
};




#endif