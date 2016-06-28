#pragma once
#include "label.hh"

template <typename T>
class Weight : public Label<T> {
  public :
    Weight();
    Weight(const T& value);
    ~Weight();
  public :
	virtual T get_weight() const;
    const Weight<T> operator+(const Weight<T>&);
	const Weight<T> operator*(const Weight<T>&);
    bool operator==(const Weight<T>&) const;
    bool operator<(const Weight<T>&) const;
    void operator<<(const Weight<T>&) const;
};

#include "weight.hxx"
