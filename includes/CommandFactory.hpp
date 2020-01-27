#ifndef COMMAND_FACTORY_HPP
#define COMMAND_FACTORY_HPP

#include "Command.hpp"

class CommandFactory
{
private:
	/* data */
public:
	CommandFactory(/* args */);
	~CommandFactory();

	static Command* CreateCommand(e_InstructionType instr, IOperand* value);
};



#endif