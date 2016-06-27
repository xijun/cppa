#include "polynomial.hh"


template <typename L, typename W>
bool Polynomial<L, W>::add_monomial(const Label<L>& label, const Weight<W>& weight)
{
    if (Polynomial<L, W>::label_is_used(label))
        return false;
    if (weight == 0)
        return true;
    monomials_.
    return true;
}