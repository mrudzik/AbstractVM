#ifndef OPERAND_INT16_HPP
#define OPERAND_INT16_HPP

#include "IOperand.hpp"

class OperandInt16 : public IOperand
{
	public:
// private:
	int16_t _value;

// public:
	OperandInt16(int16_t value);
	~OperandInt16();

	virtual e_OperandType getType() const
	{
		return e_OperandType::Int16;
	}
};


#endif