#pragma once
#include "abs_polynomial.hh"
#include <vector>
#include "label.hh"
#include "weight.hh"

/**
 * Polynomial has a variadic template to be able to deal with generic cases
 * (more details on README)
 */
template <typename L, typename W, template<class...> class Container, class... Args>
class Polynomial : public base_polynomial<L, W, Container, Args...>
{

public:

    /* Constructors + Destructors*/
    Polynomial(const Container<Args...>& monomials_) = delete;
		Polynomial();
    ~Polynomial() {}

    /* Monomial functions*/
    Container<Args...>& get_monomials() override;

    bool label_is_used(const Label<L> label) const;

    bool add_monomial(const Label<L>& label, const Weight<W>& weight) override;

    /* Polynomial functions*/
    Polynomial<L, W, Container, Args...>&
		operator+(Polynomial<L, W, Container, Args...>& polynomial);
    
		Polynomial<L, W, Container, Args...>&
		operator*(Polynomial<L, W, Container, Args...>& polynomial);

		void print(std::ostream& os) const override;

		void add_for_mult(const Label<L>& label,
											const Weight<W>& weight,
											Container<Args ...>&);

private:
    Container<Args...> monomials_;
};


/**
 *	template specialization for a vector of pair
 */
template <typename L, typename W>
class Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>> :
public base_polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>
{
public :
		Polynomial(const std::vector<std::pair<Label<L>, Weight<W>>>& monomials_) = delete;
		Polynomial();
		~Polynomial() {}

		std::vector<std::pair<Label<L>, Weight<W>>>& get_monomials() override;

		bool label_is_used(const Label<L> label) const;

		bool add_monomial(const Label<L>& label, const Weight<W>& weight) override;

		Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>&
		operator+(Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>& polynomial);

		Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>&
		operator*(Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>& polynomial);

		void print(std::ostream& os) const override;

		void add_for_mult(const Label<L>& label,
                      const Weight<W>& weight,
                      std::vector<std::pair<Label<L>, Weight<W>>>& mult);
private:
		std::vector<std::pair<Label<L>, Weight<W>>> monomials_;
};

template<typename L, typename W, template<class...> class Container, class... Args>
std::ostream& operator<<(std::ostream& os, const base_polynomial<L, W, Container, Args...>& polynomial);


template <typename L, typename W, template<class...> class Container, class... Args>
typename Container<Args ...>::iterator label_find(const Label<L>& label, const Container<Args ...>& cont);
#include "polynomial.hxx"
