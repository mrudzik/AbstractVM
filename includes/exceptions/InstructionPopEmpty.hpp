#ifndef INSTRUCTION_POP_EMPTY_EXCEPTION_HPP
#define INSTRUCTION_POP_EMPTY_EXCEPTION_HPP

#include <exception>

class InstructionPopEmptyException : public std::logic_error
{
public:
	InstructionPopEmptyException()
		: logic_error("Instruction pop on an empty stack")
	{ }
};

#endif