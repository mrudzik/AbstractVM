

#ifndef CUSTOM_EXCEPTIONS_HPP
#define CUSTOM_EXCEPTIONS_HPP

#include <string>


class CustomException : public std::logic_error
{
public:
	CustomException(std::string str)
		: logic_error("\033[21;31m" + str + "\033[0m")
	{ }
};


class DivModZeroException : public CustomException
{
public:
	DivModZeroException()
		: CustomException(
			"Division/modulo by 0")
	{ }
};

class FalseAssertException : public CustomException
{
public:
	FalseAssertException()
		: CustomException(
			"An \"assert\" instruction is not true")
	{ }
};

class InstructionPopEmptyException : public CustomException
{
public:
	InstructionPopEmptyException()
		: CustomException(
			"Instruction pop on an empty stack")
	{ }
};

class LexicalException : public CustomException
{
public:
	LexicalException()
		: CustomException(
			"The assembly program"
			" includes one or several lexical"
			" errors or syntactic errors")
	{ }
};

class MathEmptyStackException : public CustomException
{
public:
	MathEmptyStackException()
		: CustomException(
			"The stack is composed of "
			"strictly less that two values when "
			"an arithmetic instruction is executed.")
	{ }
};

class NoExitException : public CustomException
{
public:
	NoExitException()
		: CustomException(
			"The program doesn’t have an \"exit\" instruction")
	{ }
};

class OperandNotSpecifiedException : public CustomException
{
public:
	OperandNotSpecifiedException()
		: CustomException(
			"Not specified operand")
	{ }
};

class OverflowException : public CustomException
{
public:
	OverflowException()
		: CustomException(
			"Overflow on a value")
	{ }
};

class UnderflowException : public CustomException
{
public:
	UnderflowException()
		: CustomException(
			"Underflow on a value")
	{ }
};

class UnknownInstructionException : public CustomException
{
public:
	UnknownInstructionException()
		: CustomException(
			"An instruction is unknown")
	{ }
};

class UnknownOperandException : public CustomException
{
public:
	UnknownOperandException()
		: CustomException(
			"An operand is unknown")
	{ }
};


#endif