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
const Label<T> Label<T>::operator+(const Label<T>& label)
{
    if (std::is_same<T, char>::value)
        throw std::logic_error("\033[31mcannot use operator \'+\' with a label char\033[0m");
	const Label<T> output(get_label() + label.get_label());
	return output;
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
