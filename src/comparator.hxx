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

template <template <class, class> class T, class U, class V>
bool vector_sort<T, U, V>::
operator()(const T<U, V>& lhs, const T<U, V>& rhs) const
{
	return lhs.first < rhs.first;
}

template <class V>
bool vector_sort<std::pair, Label<std::string>, V>::
operator()(const std::pair<Label<std::string>, V>& lhs,
					const std::pair<Label<std::string>, V>& rhs) const
{
	std::string left = lhs.first.get_label();
	std::string right = rhs.first.get_label();
	if (left.size() != right.size())
		return left.size() < right.size();
	return left < right;
}
