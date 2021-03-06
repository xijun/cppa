#pragma once
#include <string>
#include <iostream>

template<typename T>
class Label {
  public :
    Label();
    Label(const T& value);
    ~Label();
  protected :
    T label_;
  public :
	virtual T get_label() const;
	const Label<T> operator+(const Label<T>&);
  	virtual bool operator==(const Label<T>&) const;
  	virtual bool operator<(const Label<T>&) const;
};

template<typename T>
std::ostream& operator<<(std::ostream&, const Label<T>& label);

#include "label.hxx"
