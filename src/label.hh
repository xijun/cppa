#pragma once
# include <string>

template<typename T>
class Labels {
  public :
    Labels();
    Labels(const T& value);
    ~Labels();
  private :
    T label_;
  public :
		T operator+(const Labels<T>&) const;
  	bool operator==(const Labels<T>&) const;
  	bool operator<(const Labels<T>&) const;
  	std::ostream& operator<<(const Labels<char>& label);
};

/*template<>
class Labels<char> {
  public :
    Labels();
    Labels(char& value);
    ~Labels();
  private :
    char c_;
    bool operator==(const Labels<char>&);
    bool operator<(const Labels<char>&);
    std::ostream& operator<<(const Labels<char>& label);
};*/

#include "label.hxx"
