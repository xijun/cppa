#include "polynomial.hh"
#include <cassert>

int main()
{
	std::cout << "Hello World!" << std::endl;
	Label<int> label(2);
	Label<int> label2(3);
	int toto = label + label2;
	assert(toto == 5);
	Label<std::string> label3("xx");
	Label<std::string> label4("yy");
	std::string str = label3 + label4;
	assert(str == "xxyy");

	Weight<int> w(15);
	Weight<int> w2(15);
	int res = w + w2;
	assert(res == 30);

	Weight<bool> w3(false);
	Weight<bool> w4(true);
	bool b = w3 * w4;
	assert(b == false);
}
