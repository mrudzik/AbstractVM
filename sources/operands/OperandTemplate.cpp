#include "OperandTemplate.hpp"
#include "OperandFactory.hpp"


template<typename T>
OperandTemplate::OperandTemplate(T value, e_OperandType type)
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
template <>
OperandTemplate::~OperandTemplate()
{ }

	
template<typename T>
T OperandTemplate::getValue() const
{
	return _value;
}
	
template <typename T>
std::string const OperandTemplate::toString(void) const
{
	std::stringstream ss;
	if (_type == e_OperandType::Int8)
		ss << static_cast<int>(_value); // to prevent recognizing it as char
	else
		ss << _value;
	return ss.str();
}
template <typename T>
int8_t OperandTemplate::asI8() const
{
	return static_cast<int8_t>(_value);
}
template <typename T>
int16_t OperandTemplate::asI16() const
{
	return static_cast<int16_t>(_value);
}
template <typename T>
int32_t OperandTemplate::asI32() const
{
	return static_cast<int32_t>(_value);
}
template <typename T>
float OperandTemplate::asFloat() const
{
	return static_cast<float>(_value);
}
template <typename T>
double OperandTemplate::asDouble() const 
{
	return static_cast<double>(_value);
}






