#pragma once
#include "label.hh"

template <typename T>
class Weight : public Label<T> {
  public :
    Weight();
    Weight(const T& value);
    ~Weight();
  public :
    T operator+(const Weight<T>&) const;
		T operator*(const Weight<T>&) const;
    bool operator==(const Weight<T>&) const;
    bool operator<(const Weight<T>&) const;
    void operator<<(const Weight<T>&) const;
};

#include "weight.hxx"
