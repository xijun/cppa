#include "label.hh"
#include "weight.hh"
#include <iostream>

int main()
{
	Label<char> label('x');
	Label<char> label2('y');
	char toto = label + label2;
}
