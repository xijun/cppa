#pragma once

#include <vector>
#include "label.hh"
#include "weight.hh"

template <typename L, typename W>
class Polynomial {

public:

    /* Constructors + Destructors*/
    Polynomial(const std::vector<std::pair<const Label<L>, const Weight<W>>>& monomials_) = delete;
		Polynomial();
    ~Polynomial() {}

    /* Monomial functions*/
    const std::vector<std::pair<const Label<L>, const Weight<W>>>& get_monomials() const;

    bool label_is_used(const Label<L>& label) const;

    bool add_monomial(const Label<L>& label, const Weight<W>& weight);

    /* Polynomial functions*/
    Polynomial& operator+(Polynomial& polynomial);
    Polynomial& operator*(Polynomial& polynomial);



private:

    std::vector<std::pair<const Label<L>, const Weight<W>>> monomials_;
};

template<typename L, typename W>
std::ostream& operator<<(std::ostream& os, const Polynomial<L, W>& polynomial);

#include "polynomial.hxx"
