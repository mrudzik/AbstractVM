#ifndef OPERAND_INT32_HPP
#define OPERAND_INT32_HPP

#include "IOperand.hpp"

class OperandInt32 : public IOperand
{
private:
	int32_t _value;
public:
	OperandInt32(int32_t value);
	~OperandInt32();

	virtual e_OperandType OperandDouble::getType() const;
};

#endif