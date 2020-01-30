#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "IOperand.hpp"
#include <sstream>

template <typename T>
class OperandTemplate : public IOperand
{
	public:
// private:
	T _value;
	e_OperandType _type;
	

// public:
	OperandTemplate(T value, e_OperandType type)
		: _value(value), _type(type)
	{ }

	~OperandTemplate()
	{ }

	virtual e_OperandType getType() const
	{
		return _type;
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