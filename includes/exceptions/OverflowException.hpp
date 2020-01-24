#ifndef OVERFLOW_EXCEPTION_HPP
#define OVERFLOW_EXCEPTION_HPP

#include <exception>

class OverflowException : public std::logic_error
{
public:
	OverflowException()
		: logic_error("Overflow on a value")
	{ }
};

#endif