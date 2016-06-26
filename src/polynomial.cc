#include "polynomial.hh"


template <typename L, typename W>
bool Polynomial<L, W>::add_monomial(const Label<L>& label, const Weight<W>& weight)
{
		monomials_.push_back(std::make_pair(label, weight));
    return true;
}
