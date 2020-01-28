#include "OperandDouble.hpp"

OperandDouble::OperandDouble(double value)
	: _value(value)
{

}

OperandDouble::~OperandDouble()
{
}

virtual e_OperandType OperandDouble::getType()
{
	return e_OperandType::Double;
}