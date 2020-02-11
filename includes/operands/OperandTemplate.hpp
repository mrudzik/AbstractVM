#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include <sstream>



enum e_MathType
{
	math_Add, math_Sub,
	math_Mul, math_Div
	// math_Mod
};



class AbstractOperand : public IOperand
{
	// Implemented Logical stuff here
protected:
	e_OperandType _type;

public:
	AbstractOperand(e_OperandType type)
		: _type (type)
	{	}
	virtual e_OperandType getType() const
	{
		return _type;
	}

	virtual IOperand const *operator+(IOperand const &rhs) const;
	virtual IOperand const *operator-(IOperand const &rhs) const;
	virtual IOperand const *operator*(IOperand const &rhs) const;
	virtual IOperand const *operator/(IOperand const &rhs) const;
	// virtual IOperand const *operator%(IOperand const &rhs) const;
};


template <typename T>
class OperandTemplate :  public AbstractOperand
{
	// public:
private:
	T _value;
	
	

public:
	OperandTemplate(T value, e_OperandType type)
		: AbstractOperand(type),
			_value(value)
	{ }

	~OperandTemplate()
	{ }

	

	T getValue() const
	{
		return _value;
	}

	virtual std::string const toString(void) const
	{
		std::stringstream ss;
		if (_type == e_OperandType::Int8)
			ss << static_cast<int>(_value); // to prevent recognizing it as char
		else
			ss << _value;
		return ss.str();
	}



};


#endif