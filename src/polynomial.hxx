//#pragma once

#include <algorithm>
#include <iostream>
#include "polynomial.hh"

/* Monomial functions*/
inline std::vector<std::pair<const Label, const Weight>>& Polynomial::get_monomials() const
{
    return monomials_;
}

inline bool Polynomial::label_is_used(const Label& label) const
{
    /* Search for *label* within the vector of pair */
    std::vector::iterator it = std::find_if(monomials_.begin(), monomials_.end(),
                         [](std::pair<Label, Weight>& monomial) {return monomial.first == label;});
    return it != monomials_.end();
}

/* Polynomial functions*/
inline std::ostream& Polynomial::operator<<(Polynomial& polynomial) const
{
    return std::cout;
}

inline Polynomial& Polynomial::operator+(Polynomial& polynomial)
{
    return *this;
}

inline Polynomial& Polynomial::operator*(Polynomial& polynomial)
{
    return *this;
}
