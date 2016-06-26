//#pragma once

#include <algorithm>
#include <iostream>
#include <boost/foreach.hpp>
#include "polynomial.hh"

template <typename L, typename W>
Polynomial<L, W>::Polynomial()
{
}
/* Monomial functions*/
template <typename L, typename W>
inline
const std::vector<std::pair<const Label<L>&, const Weight<W>&>>& Polynomial<L, W>::get_monomials() const
{
    return monomials_;
}

template <typename L, typename W>
inline bool Polynomial<L, W>::label_is_used(const Label<L>& label) const
{
    /* Search for *label* within the vector of pair */
    typename std::vector<std::pair<const Label<L>&, const Weight<W>&>const >::iterator it;
    it = std::find_if(monomials_.begin(), monomials_.end(),
                         [label](std::pair<Label<L>, Weight<W>>& monomial) {return monomial.first == label;});
    return it != monomials_.end();
}

/* Polynomial functions*/
template <typename L, typename W>
std::ostream& operator<<(std::ostream& os, const Polynomial<L, W>& polynomial)
{
		auto& mono = polynomial.get_monomials();
		if (mono.size() == 0)
		{
			os << "\\z";
		}
		else
		{
			bool first = true;
			BOOST_FOREACH(auto& p, mono)
			{
				if (!first)
					os << " + ";
				first = false;
				os << p.first << p.second;
			}
		}
    return os;
}

template <typename L, typename W>
inline Polynomial<L, W>& Polynomial<L, W>::operator+(Polynomial<L, W>& polynomial)
{
    return *this;
}

template <typename L, typename W>
inline Polynomial<L, W>& Polynomial<L, W>::operator*(Polynomial<L, W>& polynomial)
{
    return *this;
}

template <typename L, typename W>
bool Polynomial<L, W>::add_monomial(const Label<L>& label, const Weight<W>& weight)
{
    monomials_.push_back(std::make_pair(label, weight));
    return true;
}

