//#pragma once

#include <algorithm>
#include <iostream>
#include "boost/bind.hpp"
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
    /*it = std::find_if(monomials_.begin(), monomials_.end(),
                         [label](std::pair<Label<L>, Weight<W>>& monomial) {return monomial.first == label;});
    return it != monomials_.end();*/

    /*it = monomials_.begin();
    while (it != monomials_.end())
    {
        if (it->first == label)
            return true;
        if (!(it->first < label))
            return false;
    }
    return false;*/

    it = std::lower_bound(monomials_.begin(), monomials_.end(), label,
        boost::bind(&std::pair<const Label<L>&, const Weight<W>& const>::first, _1)
        < boost::bind(&std::pair<const Label<L>&, const Weight<W>& const>::first, _2));
    return (it != monomials_.end() && it->)
}

/* Polynomial functions*/
template <typename L, typename W>
inline std::ostream& Polynomial<L, W>::operator<<(Polynomial<L, W>& polynomial) const
{
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
