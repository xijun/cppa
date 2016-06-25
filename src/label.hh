#pragma once
# include <string>

template<typename T>
class Label {
  public :
    Label();
    Label(const T& value);
    ~Label();
  private :
    T label_;
  public :
		T operator+(const Label<T>&) const;
  	bool operator==(const Label<T>&) const;
  	bool operator<(const Label<T>&) const;
  	std::ostream& operator<<(const Label<char>& label);
};

/*template<>
class Label<char> {
  public :
    Label();
    Label(char& value);
    ~Label();
  private :
    char c_;
    bool operator==(const Label<char>&);
    bool operator<(const Label<char>&);
    std::ostream& operator<<(const Label<char>& label);
};*/

#include "label.hxx"
