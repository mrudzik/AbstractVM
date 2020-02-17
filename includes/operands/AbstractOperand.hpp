#ifndef ABSTRACT_OPERAND_HPP
#define ABSTRACT_OPERAND_HPP


#include "IOperand.hpp"
#include "CustomExceptions.hpp"
#include <sstream>
#include <cmath>


enum e_MathType
{
	math_Add, math_Sub,
	math_Mul, math_Div,
	math_Mod
};


class AbstractOperand : public IOperand
{
	// Implemented Logical stuff here
protected:
	e_OperandType _type;

public:
	AbstractOperand(e_OperandType type);

	virtual e_OperandType getType() const;
	virtual int getPrecision(void) const;
	
	virtual IOperand const *operator+(IOperand const &rhs) const;
	virtual IOperand const *operator-(IOperand const &rhs) const;
	virtual IOperand const *operator*(IOperand const &rhs) const;
	virtual IOperand const *operator/(IOperand const &rhs) const;
	virtual IOperand const *operator%(IOperand const &rhs) const;

	// Need to be defined in inherited classes
	virtual int8_t asI8() const = 0;
	virtual int16_t	asI16() const = 0;
	virtual int32_t	asI32() const = 0;
	virtual float asFloat() const = 0;
	virtual double asDouble() const = 0;
};

#endif