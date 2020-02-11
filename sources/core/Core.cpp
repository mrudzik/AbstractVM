
#include "Core.hpp"
#include "OperandFactory.hpp"
#include "EnumStringTranslator.hpp"
#include "CustomExceptions.hpp"

Core::Core(std::vector<Command*> commandList)
{// Execute commands here
	for (size_t i = 0; i < commandList.size(); i++)
	{
		e_InstructionType curInstr = commandList.at(i)->GetInstruction();
		try
		{
			switch (curInstr)
			{
			case e_InstructionType::Push:
				std::cout << "Push" << std::endl;
				Push(commandList.at(i)->GetOperand());
				break;
			case e_InstructionType::Pop:
				std::cout << "Pop" << std::endl;
				Pop();
				break;
			case e_InstructionType::Dump:
				std::cout << "Dump" << std::endl;
				Dump();
				break;
			case e_InstructionType::Assert:
				std::cout << "Assert" << std::endl;
				Assert(commandList.at(i)->GetOperand());
				break;
			case e_InstructionType::Add:
				std::cout << "Add" << std::endl;
				Math(e_MathType::math_Add);
				break;
			case e_InstructionType::Sub:
				std::cout << "Sub" << std::endl;
				Math(e_MathType::math_Sub);
				break;
			case e_InstructionType::Mul:
				std::cout << "Mul" << std::endl;
				Math(e_MathType::math_Mul);
				break;
			case e_InstructionType::Div:
				std::cout << "Div" << std::endl;
				Math(e_MathType::math_Div);
				break;
			case e_InstructionType::Mod:
				std::cout << "Mod" << std::endl;
				Math(e_MathType::math_Mod);
				break;
			case e_InstructionType::Print:
				std::cout << "Print" << std::endl;
				break;
			case e_InstructionType::Exit:
				std::cout << "Exit" << std::endl;
				return;
			default:
				break;
			}
		}
		catch(const std::exception& e)
		{
			std::cout << "Failed to execute command " <<  i + 1 << ": "<< e.what();
			commandList.at(i)->ShowCommand();
			std::cout << std::endl;
		}
		
		
	}

}

Core::~Core()
{

	for (size_t i = 0; i < _operandStack.size(); i++)
	{
		IOperand* tempObj = _operandStack.at(i);

		if (tempObj != NULL)
			delete tempObj;
		tempObj = NULL;
	}
	_operandStack.clear();
}






void Core::Push(IOperand* operand)
{
	IOperand* newOperand = OperandFactory::DuplicateOperand(operand);
	// TODO turn on when debug mode
	// std::cout << "Read : " << operand << " " << EnumStringTranslator::EnumOperand(operand->getType()) << " " << operand->toString() << "\n";
	// std::cout << "Dup : " << newOperand << " " << EnumStringTranslator::EnumOperand(newOperand->getType()) << " " << newOperand->toString() << "\n";

	_operandStack.push_back(newOperand);
}

void Core::Pop()
{
	size_t size = _operandStack.size();
	if (size <= 0)
		throw InstructionPopEmptyException();
	IOperand* tempObj = _operandStack.at(size - 1);
	delete tempObj;
	tempObj = NULL;
	_operandStack.pop_back();
}


void Core::Dump()
{
	for (size_t i = 0; i < _operandStack.size(); i++)
	{
		std::cout << _operandStack.at(i)->toString() << "\n";
	}
}

void Core::Assert(IOperand* operand)
{
	size_t size = _operandStack.size();
	if (size <= 0)
		throw InstructionPopEmptyException();

	IOperand* tempObj = _operandStack.at(size - 1);
	if (operand->toString().compare(tempObj->toString()) == 0)
		return; // Everything ok here

	throw FalseAssertException();
}


// Math

void Core::Math(e_MathType mathType)
{
	size_t size = _operandStack.size();
	if (size <= 1)
		throw MathEmptyStackException();
	
	IOperand* val1 = _operandStack.at(size - 1);
	IOperand* val2 = _operandStack.at(size - 2);
	IOperand* result = OperandFactory::MathOperands(val1, val2, mathType);
	Pop();
	Pop();
	_operandStack.push_back(result);
}



