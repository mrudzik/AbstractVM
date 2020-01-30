

#ifndef ENUM_STRING_TRANSLATOR_HPP
#define ENUM_STRING_TRANSLATOR_HPP

#include <string>
#include "IOperand.hpp"
#include "Command.hpp"

class EnumStringTranslator
{
	public:
		static std::string 	EnumOperand(e_OperandType type);
		static std::string 	EnumInstruction(e_InstructionType type);
};

#endif
