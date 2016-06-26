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
inline
T Weight<T>::operator+(const Weight<T>& weight) const
{
	return this->label_ + weight.label_;
}

template <>
inline
bool Weight<bool>::operator+(const Weight<bool>& weight) const
{
	return this->label_ || weight.label_;
}

template <typename T>
inline
T Weight<T>::operator*(const Weight<T>& weight) const
{
	return this->label_ * weight.label_;
}

template <>
inline
bool Weight<bool>::operator*(const Weight<bool>& weight) const
{
	return this->label_ && weight.label_;
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
