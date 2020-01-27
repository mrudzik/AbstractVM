#include "CommandFactory.hpp"


CommandFactory::CommandFactory(/* args */)
{
}

CommandFactory::~CommandFactory()
{
}


Command* CommandFactory::CreateCommand(e_InstructionType instr, IOperand* value)
{
	Command* result = new Command(value, instr);

	return;
}