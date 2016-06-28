#pragma once
#include <functional>
#include "label.hh"
#include "weight.hh"

/**
 * myless is needed for the flat_map argument template
 * as we are using a shortlex order, we need to adapt it
 */
template <class T>
struct myless : std::less<T>
{
	public:
			bool operator()(const T& lhs, const T& rhs) const;
};

/**
 * in case the label is a string, we implement a shortlex order
 */
template <>
struct myless<Label<std::string>> : std::less<Label<std::string>>
{
	public:
			bool operator()(const Label<std::string>& lhs, const Label<std::string>& rhs) const;
};

/**
 *	vector_sort's role is the same as myless, but we use it to sort
 *  a vector
 */
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

