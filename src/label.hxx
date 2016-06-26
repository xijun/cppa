#include "label.hh"
#include <stdexcept>
#include <type_traits>

template <typename T>
Label<T>::Label()
{
  bool is_int = std::is_same<T, int>::value;
  if (is_int)
    label_ = 0;
  else
    label_ = "\\e";
}

template <typename T>
Label<T>::Label(const T& value)
: label_(value)
{
}

template <typename T>
Label<T>::~Label()
{
}

template <>
char Label<char>::operator+(const Label<char>& label) const
{
	(void) label;
	throw std::logic_error("cannot use operator + with a label char");
}

template <typename T>
T Label<T>::operator+(const Label<T>& label) const
{
	return this->label_ + label.label_;
}


template <typename T>
bool Label<T>::operator==(const Label<T>& label) const
{
	return this->label_ == label.label_;
}

template <typename T>
bool Label<T>::operator<(const Label<T>& label) const
{
	return this->label_ < label.label_;
}

template <typename T>
void Label<T>::operator<<(const Label<T>& label) const
{
	std::cout << label.label_;
}
