#include "comparator.hh"

template <class T>
bool myless<T>::operator()(const T& lhs, const T& rhs) const
{
	std::string left = lhs.get_label();
  std::string right = rhs.get_label();
	return lhs < rhs;
}

bool myless<Label<std::string>>
::operator()(const Label<std::string>& lhs, const Label<std::string>& rhs) const
{
	std::string left = lhs.get_label();
  std::string right = rhs.get_label();
  if (left.size() != right.size())
  	return left.size() < right.size();
	return left < right;
}
