#pragma once

template<typename T>
class Weight {
  public :
    Weight();
    Weight(const T& value);
    ~Weight();
  private :
    T weight_;
  public :
    T operator+(const Weight<T>&) const;
		T operator*(const Weight<T>&) const;
    bool operator==(const Weight<T>&) const;
    bool operator<(const Weight<T>&) const;
    std::ostream& operator<<(const Weight<T>&) const;
};

#include "weight.hxx"
