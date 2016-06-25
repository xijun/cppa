#pragma once

#include <vector>
#include "label.hh"
#include "weight.hh"

template <typename L, typename W>
class Polynomial {

public:

    /* Constructors + Destructors*/
    Polynomial(const std::vector<std::pair<const Label<L>&, const Weight<W>&>>& monomials_) = delete;
    ~Polynomial() {}

    /* Monomial functions*/
    std::vector<std::pair<const Label<L>&, const Weight<W>&>>& get_monomials() const;

    bool label_is_used(const Label<L>& label) const;

    bool add_monomial(const Label<L>& label, const Weight<W>& weight);

    /* Polynomial functions*/
    std::ostream& operator<<(Polynomial& polynomial) const;
    Polynomial& operator+(Polynomial& polynomial);
    Polynomial& operator*(Polynomial& polynomial);



private:

    std::vector<std::pair<const Label<L>&, const Weight<W>&>> monomials_;
};

#include "polynomial.hxx"