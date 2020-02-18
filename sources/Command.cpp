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
		_value = NULL;
	}
}


void Command::ShowCommand()
{
	std::cout << "\033[21;36m" << EnumStringTranslator::EnumInstruction(_instrType) << "\033[0m ";
	if (_value == NULL)
		return;
	
	std::cout << EnumStringTranslator::EnumOperand(_value->getType());
	std::cout << " " << _value->toString();
}

e_InstructionType	Command::GetInstruction()
{
	return _instrType;
}

IOperand* 	Command::GetOperand()
{
	return _value;
}


Command &Command::operator= (const Command &input)
{
	_instrType = input._instrType;
	_value = input._value;
	return *this;
}
