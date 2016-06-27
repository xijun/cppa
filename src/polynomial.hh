#pragma once
#include "abs_polynomial.hh"
#include <vector>
#include "label.hh"
#include "weight.hh"

template <typename L, typename W, template<class...> class Container, class... Args>
class Polynomial : public base_polynomial<L, W, Container, Args...> {

public:

    /* Constructors + Destructors*/
    Polynomial(const Container<Args...>& monomials_) = delete;
		Polynomial();
    ~Polynomial() {}

    /* Monomial functions*/
    const Container<Args...>& get_monomials() const override;

    bool label_is_used(const Label<L>& label) const;

    bool add_monomial(const Label<L>& label, const Weight<W>& weight) override;

    /* Polynomial functions*/
    Polynomial& operator+(Polynomial& polynomial);
    Polynomial& operator*(Polynomial& polynomial);

		void print(std::ostream& os) const override;


private:
    Container<Args...> monomials_;
};

template<typename L, typename W, template<class...> class Container, class... Args>
std::ostream& operator<<(std::ostream& os, const base_polynomial<L, W, Container, Args...>& polynomial);

#include "polynomial.hxx"
