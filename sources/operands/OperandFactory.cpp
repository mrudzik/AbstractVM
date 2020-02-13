
#include "OperandFactory.hpp"
#include "CustomExceptions.hpp"
#include "ParserModule.hpp"
#include <typeinfo>


OperandFactory::OperandFactory(/* args */)
{
}

OperandFactory::~OperandFactory()
{
}


IOperand* OperandFactory::CreateOperandFromToken(std::string token)
{
	if (token.compare(0, 5, "int8(") == 0)
		return CreateTemplate<int8_t>(ParserModule::ParseInt8_t(token));
	if (token.compare(0, 6, "int16(") == 0)
		return CreateTemplate<int16_t>(ParserModule::ParseInt16_t(token));
	if (token.compare(0, 6, "int32(") == 0)
		return CreateTemplate<int32_t>(ParserModule::ParseInt32_t(token));
	if (token.compare(0, 6, "float(") == 0)
		return CreateTemplate<float>(ParserModule::ParseFloat(token));
	if (token.compare(0, 7, "double(") == 0)
		return CreateTemplate<double>(ParserModule::ParseDouble(token));

	throw UnknownOperandException();
}

template <typename T>
IOperand* OperandFactory::CreateTemplate(T value)
{
	std::string valType = typeid(value).name();

	if (valType.compare(typeid(int8_t).name()) == 0)
		return new OperandTemplate<int8_t>(value, e_OperandType::Int8);
	if (valType.compare(typeid(int16_t).name()) == 0)
		return new OperandTemplate<int16_t>(value, e_OperandType::Int16);
	if (valType.compare(typeid(int32_t).name()) == 0)
		return new OperandTemplate<int32_t>(value, e_OperandType::Int32);
	if (valType.compare(typeid(float).name()) == 0)
		return new OperandTemplate<float>(value, e_OperandType::Float);
	if (valType.compare(typeid(double).name()) == 0)
		return new OperandTemplate<double>(value, e_OperandType::Double);

	throw UnknownOperandException();
}

IOperand* OperandFactory::DuplicateOperand(IOperand* operand)
{
	e_OperandType type = operand->getType();
	switch (type)
	{
		case e_OperandType::Int8:
			return new OperandTemplate<int8_t>
				(((OperandTemplate<int8_t>*)(operand))->getValue(), type);
		case e_OperandType::Int16:
			return new OperandTemplate<int16_t>
				(((OperandTemplate<int16_t>*)(operand))->getValue(), type);
		case e_OperandType::Int32:
			return new OperandTemplate<int32_t>
				(((OperandTemplate<int32_t>*)(operand))->getValue(), type);
		case e_OperandType::Float:
			return new OperandTemplate<float>
				(((OperandTemplate<float>*)(operand))->getValue(), type);
		case e_OperandType::Double:
			return new OperandTemplate<double>
				(((OperandTemplate<double>*)(operand))->getValue(), type);
		default:
			throw UnknownOperandException();
	}
	throw std::logic_error("Failed to duplicate Operand");
}













IOperand* OperandFactory::MathOperands(const IOperand* val1, const IOperand* val2, e_MathType mathType)
{
	switch (val1->getType())
	{
	case e_OperandType::Int8:
		return MathStage1<int8_t>(val1, val2, mathType);
	case e_OperandType::Int16:
		return MathStage1<int16_t>(val1, val2, mathType);
	case e_OperandType::Int32:
		return MathStage1<int32_t>(val1, val2, mathType);
	case e_OperandType::Float:
		return MathStage1<float>(val1, val2, mathType);
	case e_OperandType::Double:
		return MathStage1<double>(val1, val2, mathType);
	}
	throw UnknownOperandException();
}

template <typename T>
IOperand* OperandFactory::MathStage1(const IOperand* val1, const IOperand* val2, e_MathType mathType)
{
	switch (val2->getType())
	{
	case e_OperandType::Int8:
		return MathStage2<T, int8_t>(val1, val2, mathType);
	case e_OperandType::Int16:
		return MathStage2<T, int16_t>(val1, val2, mathType);
	case e_OperandType::Int32:
		return MathStage2<T, int32_t>(val1, val2, mathType);
	case e_OperandType::Float:
		return MathStage2<T, float>(val1, val2, mathType);
	case e_OperandType::Double:
		return MathStage2<T, double>(val1, val2, mathType);
	}
	throw UnknownOperandException();
}

template <typename T, typename V>
IOperand* OperandFactory::MathStage2(const IOperand* val1, const IOperand* val2, e_MathType mathType)
{
	OperandTemplate<T>* cast1 = (OperandTemplate<T>*)(val1);
	OperandTemplate<V>* cast2 = (OperandTemplate<V>*)(val2);

	e_OperandType maxType;
	if (cast1->getType() >= cast2->getType())
		maxType = cast1->getType();
	else
		maxType = cast2->getType();

	if (mathType == e_MathType::math_Div || mathType == e_MathType::math_Mod)
	{
		if (cast2->getValue() == 0)
			throw DivModZeroException();
	}

	switch (mathType)
	{
	case e_MathType::math_Add:
		return CreateTemplate(cast1->getValue() + cast2->getValue());
	case e_MathType::math_Sub:
		return CreateTemplate(cast1->getValue() - cast2->getValue());
	case e_MathType::math_Mul:
		return CreateTemplate(cast1->getValue() * cast2->getValue());
	case e_MathType::math_Div:
		return CreateTemplate(cast1->getValue() / cast2->getValue());
	case e_MathType::math_Mod:
		switch (maxType)
		{
		case e_OperandType::Int8:
			return CreateTemplate(cast1->asI8() % cast2->asI8());
		case e_OperandType::Int16:
			return CreateTemplate(cast1->asI16() % cast2->asI16());
		case e_OperandType::Int32:
			return CreateTemplate(cast1->asI32() % cast2->asI32());
		case e_OperandType::Float:
			return CreateTemplate(fmod(cast1->asFloat(), cast2->asFloat()));
		case e_OperandType::Double:
			return CreateTemplate(fmod(cast1->asDouble(), cast2->asDouble()));
		}
	}
	throw UnknownOperandException();
}
