#include "label.hh"
#include <stdexcept>

template <typename T>
Labels<T>::Labels()
{
  bool is_int = std::is_same<T, int>::value;
  if (is_int)
    label_ = 0;
  else
    label_ = "\e";
}

template <typename T>
Labels<T>::Labels(const T& value)
{
  label_ = value;
}

template <typename T>
Labels<T>::~Labels()
{
}

template <typename T>
T Labels<T>::operator+(const Labels<T>& label) const
{
	return this.label_ + label.label_;
}

template <typename T>
bool Labels<T>::operator==(const Labels<T>& label) const
{
	return this.label_ == label.label_;
}

template <typename T>
bool Labels<T>::operator<(const Labels<T>& label) const
{
	return this.label_ < label.label_;
}

template <>
bool Labels<char>::operator<(const Labels<char>& label) const
{
	throw std::logic_error("cannot use operator + with a label char");
}
