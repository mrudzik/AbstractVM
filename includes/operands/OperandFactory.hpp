
#ifndef OPERAND_FACTORY_HPP
#define OPERAND_FACTORY_HPP

#include "IOperand.hpp"
#include "OperandTemplate.hpp"
// #include "OperandDouble.hpp"
// #include "OperandFloat.hpp"
// #include "OperandInt8.hpp"
// #include "OperandInt16.hpp"
// #include "OperandInt32.hpp"

// #include "Operand.hpp"

class OperandFactory
{
private:
	/* data */
public:
	OperandFactory(/* args */);
	~OperandFactory();

	static IOperand* CreateOperandFromToken(std::string token);
	
	// static IOperand* CreateInt8(int8_t value);
	// static IOperand* CreateInt16(int16_t value);
	// static IOperand* CreateInt32(int32_t value);
	// static IOperand* CreateFloat(float value);
	// static IOperand* CreateDouble(double value);
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