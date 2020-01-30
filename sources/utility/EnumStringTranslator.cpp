
#include "EnumStringTranslator.hpp"


std::string 	EnumStringTranslator::EnumOperand(e_OperandType type)
{
	switch (type)
	{
	case e_OperandType::Int8:
		return "Int8";
	case e_OperandType::Int16:
		return "Int16";
	case e_OperandType::Int32:
		return "Int32";
	case e_OperandType::Float:
		return "Float";
	case e_OperandType::Double:
		return "Double";
	default:
		return "Whooops";
	};
}


std::string 	EnumStringTranslator::EnumInstruction(e_InstructionType type)
{
	switch (type)
	{
	case e_InstructionType::Push:
		return "Push";
	case e_InstructionType::Pop:
		return "Pop";
	case e_InstructionType::Dump:
		return "Dump";
	case e_InstructionType::Assert:
		return "Assert";
	case e_InstructionType::Add:
		return "Add";
	case e_InstructionType::Sub:
		return "Sub";
	case e_InstructionType::Mul:
		return "Mul";
	case e_InstructionType::Div:
		return "Div";
	case e_InstructionType::Mod:
		return "Mod";
	case e_InstructionType::Print:
		return "Print";
	case e_InstructionType::Exit:
		return "Exit";
	default:
		return "Whooops";
	};
}