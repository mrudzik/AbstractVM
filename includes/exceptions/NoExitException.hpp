#ifndef NO_EXIT_EXCEPTION_HPP
#define NO_EXIT_EXCEPTION_HPP

#include <exception>

class NoExitException : public std::logic_error
{
public:
	NoExitException()
		: logic_error("The program doesn’t have an \"exit\" instruction")
	{ }
};

#endif