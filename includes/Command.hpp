

#ifndef COMMAND_HPP
#define COMMAND_HPP

#include "IOperand.hpp"
#include <iostream>

enum e_InstructionType
{
	Push, Pop,
	Dump, Assert,
	Add, Sub,
	Mul, Div, Mod,
	Print,
	Exit
};



class Command
{
private:
	e_InstructionType 	_instrType;
	IOperand*			_value;

public:
	Command(IOperand* newValue, e_InstructionType instruction);
	~Command();

	Command(const Command &rhs) = default;
	Command & operator= (const Command &rhs);

	void ShowCommand();
	e_InstructionType	GetInstruction();
	IOperand* GetOperand();


		
};

#endif