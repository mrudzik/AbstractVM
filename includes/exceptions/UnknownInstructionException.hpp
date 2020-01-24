
#ifndef UNKNOWN_INSTRUCTION_EXCEPTION_HPP
#define UNKNOWN_INSTRUCTION_EXCEPTION_HPP

#include <exception>

class UnknownInstructionException : public std::logic_error
{
public:
	UnknownInstructionException()
		: logic_error("An instruction is unknown")
	{ }
};

#endif