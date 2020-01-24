#ifndef FALSE_ASSERT_EXCEPTION_HPP
#define FALSE_ASSERT_EXCEPTION_HPP

#include <exception>

class MathEmptyStackException : public std::logic_error
{
public:
	MathEmptyStackException()
		: logic_error("An \"assert\" instruction is not true")
	{ }
};

#endif