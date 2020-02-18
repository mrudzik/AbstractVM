#include "OperandTemplate.hpp"
#include "OperandFactory.hpp"


template<typename T>
OperandTemplate<T>::OperandTemplate(T value, e_OperandType type)
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


template<typename T>
T OperandTemplate<T>::getValue() const
{
	return _value;
}

template<typename T>
std::string const OperandTemplate<T>::toString(void) const
{
	std::stringstream ss;
	if (_type == e_OperandType::Int8)
		ss << static_cast<int>(_value); // to prevent recognizing it as char
	else
		ss << _value;
	return ss.str();
}

template<typename T>
int8_t OperandTemplate<T>::asI8() const
{
	return static_cast<int8_t>(_value);
}

template<typename T>
int16_t OperandTemplate<T>::asI16() const
{
	return static_cast<int16_t>(_value);
}

template<typename T>
int32_t OperandTemplate<T>::asI32() const
{
	return static_cast<int32_t>(_value);
}

template<typename T>
float OperandTemplate<T>::asFloat() const
{
	return static_cast<float>(_value);
}

template<typename T>
double OperandTemplate<T>::asDouble() const 
{
	return static_cast<double>(_value);
}

template class OperandTemplate<int8_t>;
template class OperandTemplate<int16_t>;
template class OperandTemplate<int32_t>;
template class OperandTemplate<float>;
template class OperandTemplate<double>;





