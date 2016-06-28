#include <typeinfo>
#include <stdexcept>
#include <type_traits>
#include "label.hh"

template <typename T>
Label<T>::Label()
{
  if (std::is_same<T, std::string>::value)
	  label_ = "\\e";
  else
    label_ = 0;
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

template <typename T>
T Label<T>::get_label() const
{
	return label_;
}

template <typename T>
inline
Label<T>& Label<T>::operator+(const Label<T>& label)
{
	this->label_ += label.label_;
	return *this;
}

template <>
inline
Label<char>& Label<char>::operator+(const Label<char>& label)
{
	(void) label;
	throw std::logic_error("cannot use operator + with a label char");
}

template <typename T>
inline
bool Label<T>::operator==(const Label<T>& label) const
{
	return this->label_ == label.label_;
}

template <typename T>
inline
bool Label<T>::operator<(const Label<T>& label) const
{
	return label_ < label.get_label();
}

template <>
inline
bool Label<std::string>::operator<(const Label<std::string>& label) const
{
	if (get_label().size() == label.get_label().size())
		return get_label() < label.get_label();
	return get_label().size() < label.get_label().size();
}

template <typename T>
inline
std::ostream& operator<<(std::ostream& os, const Label<T>& label)
{
	os << label.get_label();
	return os;
}
