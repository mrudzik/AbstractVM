#include "OperandFloat.hpp"

OperandFloat::OperandFloat(float value)
	: _value(value)
{
}

OperandFloat::~OperandFloat()
{
}

virtual e_OperandType OperandFloat::getType()
{
	return e_OperandType::Float;
}