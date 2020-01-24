#ifndef DIV_MOD_ZERO_EXCEPTION_HPP
#define DIV_MOD_ZERO_EXCEPTION_HPP

#include <exception>

class DivModZeroException : public std::logic_error
{
public:
	DivModZeroException()
		: logic_error("Division/modulo by 0")
	{ }
};

#endif