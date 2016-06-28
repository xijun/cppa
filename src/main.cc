#include "polynomial.hh"
#include "abs_polynomial.hh"
#include <boost/container/flat_map.hpp>


int main()
{
	std::cout << "\033[33m" << "\n\t****** Label tests ******\n" << "\033[0m" << std::endl;

	/* int labels tests */
	std::cout << "\n\033[4m" << "int labels:\n\n" << "\033[0m";
	Label<int> label(2);
	std::cout << "\tprint test, label = " << label << std::endl;
	Label<int> label2(3);
	Label<int> int_label_test = label + label2;
	std::cout << "\t" << label << " + " << label2 << " = " << int_label_test
			<< (int_label_test.get_label() == label.get_label() + label2.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
			<< "\033[0m" << std::endl;

	/* string labels tests */
	std::cout << "\n\033[4m" <<"string labels:\n\n" << "\033[0m";
	Label<std::string> label3("xx");
	std::cout << "\tprint test, label = \'" << label3 << "\'" << std::endl;
	Label<std::string> label4("yy");
	Label<std::string> str_label_test = label3 + label4;
	std::cout << "\t\'" << label3 << "\' + \'" << label4 << "\' = \'" << str_label_test << "\'"
			<< (str_label_test.get_label() == label3.get_label() + label4.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
			<< "\033[0m" << std::endl;

	std::cout << "\033[33m" << "\n\t****** Weight tests ******\n" << "\033[0m" << std::endl;

	/* int weights tests */
	std::cout << "\n\033[4m" <<"int weights:\n\n" << "\033[0m";
	Weight<int> weight(15);
	std::cout << "\tprint test, weight = " << weight << std::endl;
	Weight<int> weight2(12);
	Weight<int> int_weight_test = weight + weight2;
	std::cout << "\t" << weight << " + " << weight2 << " = " << int_weight_test
		<< (int_weight_test.get_label() == weight.get_label() + weight2.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
		<< "\033[0m" << std::endl;

	/* bool weights tests */
	std::cout << "\n\033[4m" <<"int labels:\n\n" << "\033[0m";
	Weight<bool> weight3(false);
	std::cout << "\tprint test, weight = " << std::boolalpha << weight3 << std::endl;
	Weight<bool> weight4(true);
	Weight<bool> bool_weight_test = weight3 * weight4;
	std::cout << "\t" << weight3 << " + " << weight4 << " = " << bool_weight_test
		<< (bool_weight_test.get_label() == weight3.get_label() + weight4.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
		<< "\033[0m" << std::endl;
//----------------------------------------------------------------------------------------

	Label<std::string> l("x");
	Label<std::string> l2("y");
	Label<std::string> l3("z");

	Weight<int> w5(2);
	Weight<int> w6(3);
	Weight<int> w7(4);

	auto poly
	= new Polynomial<std::string, int, std::vector, std::pair<Label<std::string>, Weight<int>>>();
	poly->add_monomial(l, w5);
	poly->add_monomial(l2, w6);
	poly->add_monomial(l3, w7);
	std::cout << *poly << std::endl;

	auto p = new Polynomial<std::string, int, std::vector, std::pair<Label<std::string>, Weight<int>>>();
	p->add_monomial(l, w5);
	p->add_monomial(l2, w6);
	p->add_monomial(l3, w7);
	*poly = *poly + *p;
	std::cout << *poly << std::endl;

	auto p2 =
	new Polynomial<std::string, int, boost::container::flat_map, Label<std::string>, Weight<int>>();
	p2->add_monomial(l, w5);
  p2->add_monomial(l2, w6);
  p2->add_monomial(l3, w7);

	auto p3 = new Polynomial<std::string, int, boost::container::flat_map, Label<std::string>, Weight<int>>();
	p3->add_monomial(l, w5);
  p3->add_monomial(l2, w6);
  p3->add_monomial(l3, w7);
	*p2 = *p2 + *p3;
	std::cout << *p2 << std::endl;
}
