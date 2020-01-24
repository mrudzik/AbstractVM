#ifndef UNDERFLOW_EXCEPTION_HPP
#define UNDERFLOW_EXCEPTION_HPP

#include <exception>

class UnderflowException : public std::logic_error
{
public:
	UnderflowException()
		: logic_error("Underflow on a value")
	{ }
};

#endif