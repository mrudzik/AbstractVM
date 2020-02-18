
#include "OperandFactory.hpp"
#include "AbstractOperand.hpp"

AbstractOperand::AbstractOperand(e_OperandType type)
	: _type (type)
{	}

e_OperandType AbstractOperand::getType() const
{
	return _type;
}

int AbstractOperand::getPrecision(void) const
{
	return static_cast<int>(_type);
}



IOperand const *AbstractOperand::operator+(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Add);
}
IOperand const *AbstractOperand::operator-(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Sub);
}
IOperand const *AbstractOperand::operator*(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Mul);
}
IOperand const *AbstractOperand::operator/(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Div);
}
IOperand const *AbstractOperand::operator%(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Mod);
}
