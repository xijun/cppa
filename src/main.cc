#include "polynomial.hh"
#include "abs_polynomial.hh"
#include <boost/container/flat_map.hpp>
#include "comparator.hh"

int main()
{
	/* ******************************************** Label and Weight tests */

	std::cout << std::boolalpha << "\033[33m" << "\n\t****** Label tests ******\n" << "\033[0m" << std::endl;

	/* int labels tests */
	std::cout << "\n\033[4m" << "int labels:\n\n" << "\033[0m";
	Label<int> label(2);
	/* test << */
	std::cout << "\tprint test, label = " << label << std::endl;
	Label<int> label2(3);
	Label<int> int_label_test = label + label2;
	/* test + */
	std::cout << "\t" << label << " + " << label2 << " = " << int_label_test
			<< (int_label_test.get_label() == label.get_label() + label2.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
			<< "\033[0m" << std::endl;
	/* test < */
	std::cout << "\t" << label << " < " << label2 << " = " << (label < label2)
	<< ((label.get_label() < label2.get_label()) == (label < label2) ? "\033[32m [OK]" : "\033[31m [KO]")
	<< "\033[0m" << std::endl;
	std::cout << "\t" << label2 << " < " << label << " = " << (label2 < label)
	<< ((label2.get_label() < label.get_label()) == (label2 < label) ? "\033[32m [OK]" : "\033[31m [KO]")
	<< "\033[0m" << std::endl;
    /* test == */
    Label<int> label1(2);
    std::cout << "\t" << label << " == " << label1 << " ? " << (label == label1)
    << ((label.get_label() == label1.get_label()) == (label == label1) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    std::cout << "\t" << label << " == " << label2 << " ? " << (label == label2)
    << ((label.get_label() == label2.get_label()) == (label == label2) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;



	/* string labels tests */
	std::cout << "\n\033[4m" <<"string labels:\n\n" << "\033[0m";
	Label<std::string> label3("xx");
	/* test << */
	std::cout << "\tprint test, label = \'" << label3 << "\'" << std::endl;
	Label<std::string> label4("y");
	Label<std::string> str_label_test = label3 + label4;
	/* test + */
	std::cout << "\t\'" << label3 << "\' + \'" << label4 << "\' = \'" << str_label_test << "\'"
			<< (str_label_test.get_label() == label3.get_label() + label4.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
			<< "\033[0m" << std::endl;
	/* test < */
	unsigned long label3_size = label3.get_label().size();
	unsigned long label4_size = label4.get_label().size();
	std::cout << "\t" << label3 << " < " << label4 << " = " << (label3 < label4) << ((label3_size < label4_size
		 || (label3_size == label4_size && label3.get_label() < label4.get_label())) == (label3 < label4) ?
		"\033[32m [OK]" : "\033[31m [KO]") << "\033[0m" << std::endl;
	std::cout << "\t" << label4 << " < " << label3 << " = " << (label4 < label3) << ((label4_size < label3_size ||
			(label4_size == label3_size && label4.get_label() < label3.get_label())) == (label4 < label3)?
		"\033[32m [OK]" : "\033[31m [KO]") << "\033[0m" << std::endl;
    /* test == */
    Label<std::string> label5("xx");
    std::cout << "\t" << label3 << " == " << label4 << " ? " << (label3 == label4)
    << ((label3.get_label() == label4.get_label()) == (label3 == label4) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    std::cout << "\t" << label3 << " == " << label5 << " ? " << (label3 == label5)
    << ((label3.get_label() == label5.get_label()) == (label3 == label5) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;



	std::cout << "\033[33m" << "\n\t****** Weight tests ******\n" << "\033[0m" << std::endl;

	/* int weights tests */
	std::cout << "\n\033[4m" <<"int weights:\n\n" << "\033[0m";
	Weight<int> weight(15);
    /* test << */
	std::cout << "\tprint test, weight = " << weight << std::endl;
	Weight<int> weight2(12);
	Weight<int> int_weight_test = weight + weight2;
    /* test + */
	std::cout << "\t" << weight << " + " << weight2 << " = " << int_weight_test
		<< (int_weight_test.get_label() == weight.get_label() + weight2.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
		<< "\033[0m" << std::endl;
    /* test < */
    std::cout << "\t" << weight << " < " << weight2 << " = " << (weight < weight2)
    << ((weight.get_label() < weight2.get_label()) == (weight < weight2) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    std::cout << "\t" << weight2 << " < " << weight << " = " << (weight2 < weight)
    << ((weight2.get_label() < weight.get_label()) == (weight2 < weight) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    /* test == */
    Weight<int> weight1(15);
    std::cout << "\t" << weight << " == " << weight1 << " ? " << (weight == weight1)
    << ((weight.get_label() == weight1.get_label()) == (weight == weight1) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    std::cout << "\t" << weight << " == " << weight2 << " ? " << (weight == weight2)
    << ((weight.get_label() == weight2.get_label()) == (weight == weight2) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    /* test * */
    std::cout << "\t" << weight << " * " << weight2 << " = " << weight * weight2
    << (weight * weight2 == weight.get_label() * weight2.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;


	/* bool weights tests */
	std::cout << "\n\033[4m" <<"bool weights:\n\n" << "\033[0m";
	Weight<bool> weight3(false);
    /* test << */
	std::cout << "\tprint test, weight = " << weight3 << std::endl;
	Weight<bool> weight4(true);
	Weight<bool> bool_weight_test = weight3 + weight4;
    /* test + */
	std::cout << "\t" << weight3 << " + " << weight4 << " = " << bool_weight_test
		<< (bool_weight_test.get_label() == weight3.get_label() + weight4.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
		<< "\033[0m" << std::endl;
    /* test < */
    std::cout << "\t" << weight3 << " < " << weight4 << " = " << (weight3 < weight4)
    << ((weight3.get_label() < weight4.get_label()) == (weight3 < weight4) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    std::cout << "\t" << weight4 << " < " << weight3 << " = " << (weight4 < weight3)
    << ((weight4.get_label() < weight3.get_label()) == (weight4 < weight3) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    /* test == */
    Weight<bool> weight5(true);
    std::cout << "\t" << weight4 << " == " << weight5 << " ? " << (weight4 == weight5)
    << ((weight4.get_label() == weight5.get_label()) == (weight4 == weight5) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    std::cout << "\t" << weight3 << " == " << weight4 << " ? " << (weight3 == weight4)
    << ((weight3.get_label() == weight4.get_label()) == (weight3 == weight4) ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    /* test * */
    std::cout << "\t" << weight3 << " * " << weight4 << " = " << weight3 * weight4
    << (weight3 * weight4 == weight3.get_label() * weight4.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;
    std::cout << "\t" << weight5 << " * " << weight4 << " = " << weight5 * weight4
    << (weight5 * weight4 == weight5.get_label() * weight4.get_label() ? "\033[32m [OK]" : "\033[31m [KO]")
    << "\033[0m" << std::endl;

/*
 *
 *
>>>>>>> [BENCH][LABEL] label::operator< done
//----------------------------------------------------------------------------------------

	Label<std::string> l("x");
	Label<std::string> l2("y");
	Label<std::string> l3("z");
	Label<std::string> l4("xy");

	Weight<int> w5(2);
	Weight<int> w6(3);
	Weight<int> w7(4);
	Weight<std::string> w8("toto");
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

	*poly = *poly * *p;
	std::cout << *poly << std::endl;

	auto p2 =
	new Polynomial<std::string, int,
								boost::container::flat_map,
								Label<std::string>, Weight<int>,
								myless<Label<std::string>>>();
	p2->add_monomial(l, w5);
  p2->add_monomial(l2, w6);
  p2->add_monomial(l3, w7);
	auto p3 = new Polynomial<std::string, int,
													boost::container::flat_map,
													Label<std::string>,
													Weight<int>,
													myless<Label<std::string>>>();
	p3->add_monomial(l, w5);
  p3->add_monomial(l2, w6);
  p3->add_monomial(l3, w7);
	*p2 = *p2 + *p3;
	std::cout << *p2 << std::endl;

	*p2 = *p2 * *p3;
	std::cout << *p2 << std::endl;*/
}
