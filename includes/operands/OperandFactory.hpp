
#ifndef OPERAND_FACTORY_HPP
#define OPERAND_FACTORY_HPP

#include "IOperand.hpp"
#include "OperandTemplate.hpp"

class OperandFactory
{
public:
	OperandFactory(/* args */);
	~OperandFactory();

	static IOperand* CreateOperandFromToken(std::string token);
	template <typename T>
	static IOperand* CreateTemplate(T value);
	static IOperand* DuplicateOperand(IOperand* operand);
	static IOperand* MathOperands(const IOperand* val1, const IOperand* val2, e_MathType mathType);

	template <typename T>
	static IOperand* MathStage1(const IOperand* val1, const IOperand* val2, e_MathType mathType);
	template <typename T, typename V>
	static IOperand* MathStage2(const IOperand* val1, const IOperand* val2, e_MathType mathType);


};

#endif