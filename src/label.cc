# include "label.hh"

template <typename T>
Labels<T>::Labels()
{
  bool is_int = std::is_same<T, int>::value;
  if (is_int)
    label_ = 0;
  else
    label_ = "\e";
}

template <typename T>
Labels<T>::Labels(T& value)
{
  label_ = value;
}

template <typename T>
Labels<T>::~Labels()
{
}
