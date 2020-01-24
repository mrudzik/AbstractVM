#ifndef LEXICAL_EXCEPTION_HPP
#define LEXICAL_EXCEPTION_HPP

#include <exception>

class LexicalException : public std::logic_error
{
public:
	LexicalException()
		: logic_error("The assembly program"
			"includes one or several lexical"
			"errors or syntactic errors")
	{ }
};

#endif