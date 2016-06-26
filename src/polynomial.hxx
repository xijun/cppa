//#pragma once

#include <algorithm>
#include <iostream>
#include <boost/foreach.hpp>
#include "polynomial.hh"

/* Monomial functions*/
template <typename L, typename W>
inline std::vector<std::pair<const Label<L>&, const Weight<W>&>>& Polynomial<L, W>::get_monomials() const
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
inline std::ostream& Polynomial<L, W>::operator<<(Polynomial<L, W>& polynomial) const
{
		if (monomials_.size() == 0)
		{
			std::cout << "\\z";
		}
		else
		{
			bool first = true;
			BOOST_FOREACH(auto& p, monomials_)
			{
				if (!first)
					std::cout << " + ";
				first = false;
				std::cout << p.first << p.second;
			}
		}
    return std::cout;
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
