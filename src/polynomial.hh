#pragma once
#include "abs_polynomial.hh"
#include <vector>
#include "label.hh"
#include "weight.hh"

template <typename L, typename W>
class Polynomial : public base_polynomial<L, W> {

public:

    /* Constructors + Destructors*/
    Polynomial(const std::vector<std::pair<const Label<L>, const Weight<W>>>& monomials_) = delete;
		Polynomial();
    ~Polynomial() {}

    /* Monomial functions*/
    const std::vector<std::pair<const Label<L>, const Weight<W>>>& get_monomials() const override;

    bool label_is_used(const Label<L>& label) const;

    bool add_monomial(const Label<L>& label, const Weight<W>& weight) override;

    /* Polynomial functions*/
    Polynomial& operator+(Polynomial& polynomial);
    Polynomial& operator*(Polynomial& polynomial);

		void print(std::ostream& os) const override;


private:
    std::vector<std::pair<const Label<L>, const Weight<W>>> monomials_;
};

template<typename L, typename W>
std::ostream& operator<<(std::ostream& os, const base_polynomial<L, W>& polynomial);

#include "polynomial.hxx"
