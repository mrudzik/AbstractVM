#include "OperandInt32.hpp"

OperandInt32::OperandInt32(int32_t value)
	: _value(value)
{
}

OperandInt32::~OperandInt32()
{
}

virtual e_OperandType OperandInt32::getType()
{
	return e_OperandType::Int32;
}