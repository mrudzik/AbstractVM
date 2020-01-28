#ifndef OPERAND_INT32_HPP
#define OPERAND_INT32_HPP

#include "IOperand.hpp"

class OperandInt32 : public IOperand
{
	public: // temp
// private:
	int32_t _value;
// public:
	OperandInt32(int32_t value);
	~OperandInt32();

	virtual e_OperandType getType() const
	{
		return e_OperandType::Int32;
	}
};

#endif