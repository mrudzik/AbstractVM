
#ifndef I_OPERAND_HPP
#define I_OPERAND_HPP

#include <string>

enum e_OperandType
{
	Int8,
	Int16,
	Int32,
	Float,
	Double
};

class IOperand
{

public:
	// Precision of the type of the instance
	virtual int getPrecision(void) const = 0;
	// Type of the instance
	virtual e_OperandType getType(void) const = 0;
	// Math
	virtual IOperand const * operator+(IOperand const &rhs) const = 0;
	virtual IOperand const * operator-(IOperand const &rhs) const = 0;
	virtual IOperand const * operator*(IOperand const &rhs) const = 0;
	virtual IOperand const * operator/(IOperand const &rhs) const = 0;
	virtual IOperand const * operator%(IOperand const &rhs) const = 0;

	// // String representation of the instance
	virtual std::string const toString(void) const = 0;

	virtual ~IOperand(void) {}
};


#endif