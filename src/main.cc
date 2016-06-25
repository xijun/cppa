#include "label.hh"
#include "weight.hh"
#include <iostream>

int main()
{
	Labels<char> label('x');
	Labels<char> label2('y');
	char toto = label + label2;
}
