#include "OperandTemplate.hpp"
#include "OperandFactory.hpp"

template <typename T>
IOperand const *OperandTemplate<T>::operator+(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(&this, &rhs, e_MathType::math_Add);
}
template <typename T>
IOperand const *OperandTemplate<T>::operator-(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(&this, &rhs, e_MathType::math_Sub);
}
template <typename T>
IOperand const *OperandTemplate<T>::operator*(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(&this, &rhs, e_MathType::math_Mul);
}
template <typename T>
IOperand const *OperandTemplate<T>::operator/(IOperand const &rhs) const
{
	return OperandFactory::MathOperands(&this, &rhs, e_MathType::math_Div);
}
// template <typename T>
// IOperand const *OperandTemplate<T>::operator%(IOperand const &rhs) const
// {
// 	return OperandFactory::MathOperands(&this, &rhs, e_MathType::math_Mod);
// }


// template <typename T>
// OperandTemplate::Operand(T value, e_OperandType type)
// 	: _value(value), _type(type)
// {

// }

// OperandTemplate::~Operand()
// {
// }
