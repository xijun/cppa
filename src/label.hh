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
		virtual T operator+(const Label<T>&) const;
  	virtual bool operator==(const Label<T>&) const;
  	virtual bool operator<(const Label<T>&) const;
		virtual void operator<<(const Label<T>& label) const;
};


#include "label.hxx"
