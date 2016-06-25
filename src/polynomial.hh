#pragma once

#include <vector>
#include "label.hh"
#include "weight.hh"

class Polynomial {

public:

    /* Constructors + Destructors*/
    Polynomial(const std::vector<std::pair<const Label, const Weight>>& monomials_) = delete;
    ~Polynomial() {}

    /* Monomial functions*/
    std::vector<std::pair<const Label, const Weight>>& get_monomials() const;

    bool label_is_used(const Label& label) const;

    bool add_monomial(const Label& label, const Weight& weight);

    /* Polynomial functions*/
    std::ostream& operator<<(Polynomial& polynomial) const;
    Polynomial& operator+(Polynomial& polynomial);
    Polynomial& operator*(Polynomial& polynomial);



private:

    std::vector<std::pair<const Label, const Weight>> monomials_;
};

#include "polynomial.hxx"