#ifndef UNKNOWN_OPERAND_EXCEPTION_HPP
#define UNKNOWN_OPERAND_EXCEPTION_HPP

#include <exception>

class UnknownOperandException : public std::logic_error
{
public:
	UnknownOperandException()
		: logic_error("An operand is unknown")
	{ }
};

#endif