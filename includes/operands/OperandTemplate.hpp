#ifndef OPERAND_HPP
#define OPERAND_HPP

#include "AbstractOperand.hpp"

template <typename T>
class OperandTemplate :  public AbstractOperand
{
	// public:
private:
	T _value;

public:
	OperandTemplate(T value, e_OperandType type);
	~OperandTemplate();

	

	T getValue() const;
	
	virtual std::string const toString(void) const;

	virtual int8_t asI8() const;
	virtual int16_t asI16() const;
	virtual int32_t asI32() const;
	virtual float asFloat() const;
	virtual double asDouble() const;
};


#endif