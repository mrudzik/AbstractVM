#include "OperandTemplate.hpp"
#include "OperandFactory.hpp"

IOperand const *AbstractOperand::operator+(IOperand const &rhs) const
{
	// (void)rhs;
	// 	return OperandFactory::CreateTemplate<int8_t>(123);

	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Add);
}
IOperand const *AbstractOperand::operator-(IOperand const &rhs) const
{
	// (void)rhs;
		// return OperandFactory::CreateTemplate<int8_t>(123);

	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Sub);
}
IOperand const *AbstractOperand::operator*(IOperand const &rhs) const
{
	// (void)rhs;
	// 	return OperandFactory::CreateTemplate<int8_t>(123);

	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Mul);
}
IOperand const *AbstractOperand::operator/(IOperand const &rhs) const
{
	// (void)rhs;
	// 	return OperandFactory::CreateTemplate<int8_t>(123);

	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Div);
}
// template <typename T>
IOperand const *AbstractOperand::operator%(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(this, &rhs, e_MathType::math_Mod);
}


// template <typename T>
// OperandTemplate::Operand(T value, e_OperandType type)
// 	: _value(value), _type(type)
// {

// }

// OperandTemplate::~Operand()
// {
// }
