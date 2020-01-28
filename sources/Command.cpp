#include "Command.hpp"

Command::Command(IOperand* newValue, e_InstructionType instr)
	: _instrType(instr), _value(newValue)
{}

Command::~Command()
{}


void Command::ShowCommand()
{
	std::cout << "\n" << _instrType << " ";
	if (_value == NULL)
	{
		std::cout << "NULL";
		return;
	}
	std::cout << _value;
	
}
