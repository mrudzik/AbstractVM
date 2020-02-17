
#ifndef CORE_HPP
#define CORE_HPP

#include <vector>
#include "Command.hpp"
#include "OperandTemplate.hpp"
class Core
{
private:
	/* data */
	std::vector<IOperand*> _operandStack;

	/* incapsulated functions */
	void Push(IOperand* operand);
	void Pop();
	void Dump();
	void Assert(IOperand* operand);
	void Math(e_MathType mathType);
	void Print();
public:
	Core(std::vector<Command*> commandList);
	~Core();
};



#endif