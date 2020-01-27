#ifndef MATH_EMPTY_STACK_EXCEPTION_HPP
#define MATH_EMPTY_STACK_EXCEPTION_HPP

#include <exception>

class MathEmptyStackException : public std::logic_error
{
public:
	MathEmptyStackException()
		: logic_error("The stack is composed of "
			"strictly less that two values when "
			"an arithmetic instruction is executed.")
	{ }
};

#endif