#include <algorithm>
#include <iostream>
#include <boost/foreach.hpp>
#include "boost/bind.hpp"
#include <boost/bind.hpp>
#include "polynomial.hh"

template <typename L, typename W, template<class...> class Container, class... Args>
Polynomial<L, W, Container, Args...>::Polynomial()
{
}

template <typename L, typename W>
Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>
::Polynomial()
{
}

/* Monomial functions*/
template <typename L, typename W, template<class...> class Container, class... Args>
inline
const Container<Args...>& Polynomial<L, W, Container, Args...>::get_monomials() const
{
    return monomials_;
}

template <typename L, typename W>
inline
const std::vector<std::pair<Label<L>, Weight<W>>>&
Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>
::get_monomials() const
{
	return monomials_;
}


template <typename L, typename W, template<class...> class Container, class... Args>
inline bool Polynomial<L, W, Container, Args...>::label_is_used(const Label<L>& label) const
{
    /* Search for *label* within the vector of pair */
    typename std::vector<std::pair<const Label<L>&, const Weight<W>&>const >::iterator it;
    /*it = std::find_if(monomials_.begin(), monomials_.end(),
                         [label](std::pair<Label<L>, Weight<W>>& monomial) {return monomial.first == label;});
    return it != monomials_.end();*/

    it = monomials_.begin();
    while (it != monomials_.end())
    {
        if (it->first == label)
            return true;
        if (!(it->first < label))
            return false;
				it++;
    }
    return false;

    /*it = std::lower_bound(monomials_.begin(), monomials_.end(), label,
        boost::bind(&std::pair<const Label<L>&, const Weight<W>& const>::first, _1)
        < boost::bind(&std::pair<const Label<L>&, const Weight<W>& const>::first, _2));
    return (it != monomials_.end() && it->)*/
}

/* Polynomial functions*/

template <typename L, typename W, template<class...> class Container, class... Args>
std::ostream& operator<<(std::ostream& os, const base_polynomial<L, W, Container, Args...>& polynomial)
{
	polynomial.print(os);
	return os;
}

template <typename L, typename W, template<class...> class Container, class... Args>
void Polynomial<L, W, Container, Args...>::print(std::ostream& os) const
{
    auto& mono = this->get_monomials();
    if (mono.size() == 0)
    {
      os << "\\z";
    }
    else
    {
      bool first = true;
      BOOST_FOREACH(auto& p, mono)
      {
        if (!first)
          os << " + ";
        first = false;
        os << '<' << p.second << '>' << p.first;
      }
    }
}

template <typename L, typename W>
void Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>
::print(std::ostream& os) const
{
	  auto& mono = this->get_monomials();
    if (mono.size() == 0)
 																	   {
      os << "\\z";
    }
    else
    {
      bool first = true;
      BOOST_FOREACH(auto& p, mono)
      {
        if (!first)
          os << " + ";
        first = false;
        os << '<' << p.second << '>' << p.first;
      }
    }

}

template <typename L, typename W, template<class...> class Container, class... Args>
Polynomial<L, W, Container, Args...>& 
Polynomial<L, W, Container, Args...>
::operator+(Polynomial<L, W, Container, Args...>& polynomial)
{
		auto& arg1 = this->get_monomials();
		auto& arg2 = polynomial.get_monomials();
		BOOST_FOREACH(auto& p, arg2)
		{
			if (label_is_used(p.first))
			{
				auto result = std::find(arg1.begin(), arg1.end(), p);
				*result.second = *result.second + p.second;
			}
			else
				add_monomial(p.first, p.second);
		}
		return *this;
}

template <typename L, typename W>
Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>&
Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>
::operator+(Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>& polynomial)
{
	auto& arg1 = this->get_monomials();
	auto& arg2 = polynomial.get_monomials();
	BOOST_FOREACH(auto& p, arg2)
	{
		if (label_is_used(p.first))
		{
			auto result = std::find(arg1.begin(), arg1.end(), p);
			*result.second = *result.second + p.second;
		}
		else
			add_monomial(p.first, p.second);
	}
	return *this;
}

template <typename L, typename W, template<class...> class Container, class... Args>
inline  Polynomial<L, W, Container, Args...>& 
Polynomial<L, W, Container, Args...>
::operator*(Polynomial<L, W, Container, Args...>& polynomial)
{
		auto& arg1 = this->get_monomials();
		auto& arg2 = polynomial.get_monomials();
		Container<Args ...> mult;
		BOOST_FOREACH(auto& p, arg1)
		{
			BOOST_FOREACH(auto& p2, arg2)
			{
				auto res = std::make_pair(p.first + p2.first, p.second * p2.second);
			}
		}
    return *this;
}

template <typename L, typename W, template<class...> class Container, class... Args>
bool Polynomial<L, W, Container, Args...>
::add_monomial(const Label<L>& label, const Weight<W>& weight)
{
	auto pair = std::make_pair(label, weight);
  auto p = monomials_.insert(pair);
  return p.second;
}

template <typename L, typename W>
bool Polynomial<L, W, std::vector, std::pair<Label<L>, Weight<W>>>
::add_monomial(const Label<L>& label, const Weight<W>& weight)
{
    if (label_is_used(label))
        return false;
    if (weight.get_label() == 0)
        return true;
		auto pair = std::make_pair(label, weight);
  	monomials_.push_back(pair);
    return true;
}

template <typename L, typename W, template<class...> class Container, class... Args>
void add_for_mult(const Label<L>& label, const Weight<W>& weight, Container<Args ...>& cont)
{
	auto it = label_find(label, cont);
	if (it != cont.end())
	{
		auto pair = std::make_pair(label, weight);
		cont.insert(pair);
	}
	else
	{
		*it.first = *it.first + label;
		*it.second = *it.second + weight;
	}
}

template <typename L, typename W, template<class...> class Container, class... Args>
typename Container<Args ...>::iterator
label_find(const Label<L>& label, const Container<Args ...>& cont)
{
    auto it = cont.begin();
    while (it != cont.end())
        it++;
    return it;
}
