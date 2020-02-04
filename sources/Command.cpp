#include "Command.hpp"
#include "EnumStringTranslator.hpp"

Command::Command(IOperand* newValue, e_InstructionType instr)
	: _instrType(instr), _value(newValue)
{}

Command::~Command()
{
	if (_value != NULL)
	{
		delete _value;
	}
}


void Command::ShowCommand()
{
	std::cout << "\n" << EnumStringTranslator::EnumInstruction(_instrType) << " ";
	if (_value == NULL)
		return;
	
	std::cout << EnumStringTranslator::EnumOperand(_value->getType());
	std::cout << " " << _value->toString();
}

e_InstructionType	Command::GetInstruction()
{
	return _instrType;
}
