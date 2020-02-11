#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include "CustomExceptions.hpp"
#include <sstream>
#include <cmath>


enum e_MathType
{
	math_Add, math_Sub,
	math_Mul, math_Div,
	math_Mod
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
	virtual int getPrecision(void) const
	{
		return static_cast<int>(_type);
	}
	
	virtual IOperand const *operator+(IOperand const &rhs) const;
	virtual IOperand const *operator-(IOperand const &rhs) const;
	virtual IOperand const *operator*(IOperand const &rhs) const;
	virtual IOperand const *operator/(IOperand const &rhs) const;
	virtual IOperand const *operator%(IOperand const &rhs) const;


	virtual int8_t asI8() const = 0;
	virtual int16_t asI16() const = 0;
	virtual int32_t asI32() const = 0;
	virtual float asFloat() const = 0;
	virtual double asDouble() const = 0;
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
	{
		if (_type == e_OperandType::Float || _type == e_OperandType::Double)
		{ // Check on inf and nan
			if (std::isnan(_value))
				throw CustomException("Value is NaN");
			if (std::isinf(_value))
				throw CustomException("Value is Inf");
		}
	}

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

	virtual int8_t asI8() const
	{
		return static_cast<int8_t>(_value);
	}
	virtual int16_t asI16() const
	{
		return static_cast<int16_t>(_value);
	}
	virtual int32_t asI32() const
	{
		return static_cast<int32_t>(_value);
	}
	virtual float asFloat() const
	{
		return static_cast<float>(_value);
	}
	virtual double asDouble() const 
	{
		return static_cast<double>(_value);
	}


};


#endif