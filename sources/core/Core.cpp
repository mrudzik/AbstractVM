
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
				Push(commandList.at(i)->GetOperand());
				break;
			case e_InstructionType::Pop:
				Pop();
				break;
			case e_InstructionType::Dump:
				Dump();
				break;
			case e_InstructionType::Assert:
				Assert(commandList.at(i)->GetOperand());
				break;
			case e_InstructionType::Add:
				Math(e_MathType::math_Add);
				break;
			case e_InstructionType::Sub:
				Math(e_MathType::math_Sub);
				break;
			case e_InstructionType::Mul:
				Math(e_MathType::math_Mul);
				break;
			case e_InstructionType::Div:
				Math(e_MathType::math_Div);
				break;
			case e_InstructionType::Mod:
				Math(e_MathType::math_Mod);
				break;
			case e_InstructionType::Print:
				Print();
				break;
			case e_InstructionType::Exit:
				return;
			default:
				throw UnknownInstructionException();
			}
		}
		catch(const std::exception& e)
		{
			std::cout << "Failed to execute command " <<  i + 1 << ": ";
			commandList.at(i)->ShowCommand();
			std::cout << "\n\t" << e.what() << std::endl;
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
	// std::cout << "-Dump-\n";
	for (size_t i = 0; i < _operandStack.size(); i++)
	{
		std::cout << _operandStack.at(i)->toString() << "\n";
	}
	// std::cout << "------\n";
}

void Core::Assert(IOperand* operand)
{
	size_t size = _operandStack.size();
	if (size <= 0)
		throw InstructionPopEmptyException();

	IOperand* tempObj = _operandStack.at(size - 1);
	if (operand->getType() == tempObj->getType())
	{ // Check on the same type
		if (operand->toString().compare(tempObj->toString()) == 0)
			return; // Everything ok here
	}
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
	IOperand* result = OperandFactory::MathOperands(val2, val1, mathType);
	Pop();
	Pop();
	_operandStack.push_back(result);
}

void Core::Print()
{
	size_t size = _operandStack.size();
	if (size <= 0)
		throw InstructionPopEmptyException();
	IOperand* val = _operandStack.at(size - 1);
	
	if (val->getType() != e_OperandType::Int8)
		throw FalseAssertException();
	OperandTemplate<int8_t>* cast = dynamic_cast<OperandTemplate<int8_t>*>(val);
	std::cout << cast->getValue() << "\n";
}


