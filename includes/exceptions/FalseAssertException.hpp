#ifndef FALSE_ASSERT_EXCEPTION_HPP
#define FALSE_ASSERT_EXCEPTION_HPP

#include <exception>

class FalseAssertException : public std::logic_error
{
public:
	FalseAssertException()
		: logic_error("An \"assert\" instruction is not true")
	{ }
};

#endif