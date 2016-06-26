
#pragma once
#include <vector>
#include "label.hh"
#include "weight.hh"

template <typename L, typename W>
class base_polynomial {
	public :
		virtual ~base_polynomial() {}
		virtual const std::vector<std::pair<const Label<L>, const Weight<W>>>& get_monomials() const = 0;
		virtual bool add_monomial(const Label<L>& label, const Weight<W>& weight) = 0;
		virtual void print(std::ostream&) const = 0;
};
