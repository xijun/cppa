#pragma once
#include <functional>
#include "label.hh"

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

#include "comparator.hxx"

