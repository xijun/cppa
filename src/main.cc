#include "polynomial.hh"
#include <boost/container/flat_map.hpp>
#include "abs_polynomial.hh"
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

//----------------------------------------------------------------------------------------

	Label<std::string> l("x");
	Label<std::string> l2("y");
	Label<std::string> l3("z");

	Weight<int> w5(2);
	Weight<int> w6(3);
	Weight<int> w7(4);

	base_polynomial<std::string, int, boost::container::flat_map, Label<std::string>, Weight<int>>* poly
	= new Polynomial<std::string, int, boost::container::flat_map, Label<std::string>, Weight<int>>();
	poly->add_monomial(l, w5);
	poly->add_monomial(l2, w6);
	poly->add_monomial(l3, w7);
	std::cout << *poly;
}
