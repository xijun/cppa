#include "weight.hh"

template <typename T>
Weight<T>::Weight()
{
	weight_ = 0;
}

template <typename T>
Weight<T>::Weight(const T& value)
: weight_(value)
{
}

template <typename T>
Weight<T>::~Weight()
{
}

template <typename T>
T Weight<T>::operator+(const Weight<T>& weight) const
{
	return this.weight_ + weight.weight_;
}

template <typename T>
T Weight<T>::operator*(const Weight<T>& weight) const
{
	return this.weight_ * weight.weight_;
}

template <typename T>
bool Weight<T>::operator==(const Weight<T>& weight) const
{
	return this.weight_ == weight.weight_;
}

template <typename T>
bool Weight<T>::operator<(const Weight<T>& weight) const
{
	return this.weight_ < weight.weight_;
}

template <typename T>
std::ostream& Weight<T>::operator<<(const Weight<T>& weight) const
{
}
