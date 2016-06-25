#pragma once

#include <vector>
#include "label.hh"
#include "weight.hh"

class polynomial {

public:

    const std::vector<std::pair<Label, Weight>>& get_monomials() const
    {
        return monomials_;
    }

    void add_monomial(Label label, Weight weight)
    {
        
    }

private:
    std::vector<std::pair<Label, Weight>> monomials_;
};
