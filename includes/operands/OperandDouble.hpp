#ifndef OPERAND_DOUBLE_HPP
#define OPERAND_DOUBLE_HPP

#include "IOperand.hpp"

class OperandDouble : public IOperand
{
private:
	double _value;
public:
	OperandDouble(double value);
	~OperandDouble();

	virtual e_OperandType OperandDouble::getType();
};

#endif