#include "weight.hh"
#include <iostream>

template <typename T>
Weight<T>::Weight()
: Label<T>(0)
{
}

template <typename T>
Weight<T>::Weight(const T& value)
: Label<T>(value)
{
}

template <typename T>
Weight<T>::~Weight()
{
}

template <typename T>
T Weight<T>::get_weight() const
{
	return this->get_label();
}

template <typename T>
inline
const Weight<T> Weight<T>::operator+(const Weight<T>& weight)
{
	const Weight<T> output(get_weight() + weight.get_weight());
    return output;
}

template <typename T>
inline
const Weight<T> Weight<T>::operator*(const Weight<T>& weight)
{
	const Weight<T> output(get_weight() * weight.get_weight());
    return output;
}

template <typename T>
inline
bool Weight<T>::operator==(const Weight<T>& weight) const
{
	return this->label_ == weight.label_;
}

template <typename T>
inline
bool Weight<T>::operator<(const Weight<T>& weight) const
{
	return this->label_ < weight.label_;
}

template <typename T>
inline
void Weight<T>::operator<<(const Weight<T>& weight) const
{
	std::cout << weight.label_;
}
