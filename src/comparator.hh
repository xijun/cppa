#pragma once
#include <functional>
#include "label.hh"
#include "weight.hh"

template <class T>
struct myless : std::less<T>
{
	public:
			bool operator()(const T& lhs, const T& rhs) const;
};

template <>
struct myless<Label<std::string>> : std::less<Label<std::string>>
{
	public:
			bool operator()(const Label<std::string>& lhs, const Label<std::string>& rhs) const;
};

template <template <class, class> class T, class U, class V>
struct vector_sort :
				std::less<T<U, V>>
{
	public:
			bool operator()(const T<U, V>& lhs,
											const T<U, V>& rhs) const;
};

template <class V>
struct vector_sort<std::pair, Label<std::string>, V> :
			std::less<std::pair<Label<std::string>, V>>
{
	public:
			bool operator()(const std::pair<Label<std::string>, V>& lhs,
											const std::pair<Label<std::string>, V>& rhs) const;
};
#include "comparator.hxx"

