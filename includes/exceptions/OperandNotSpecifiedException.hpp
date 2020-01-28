#ifndef OPERAND_NOT_SPECIFIED_EXCEPTION_HPP
#define OPERAND_NOT_SPECIFIED_EXCEPTION_HPP

#include <exception>

class OperandNotSpecifiedException : public std::logic_error
{
public:
	OperandNotSpecifiedException()
		: logic_error("Not specified operand")
	{ }
};

#endif