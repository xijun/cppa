#include <boost/container/flat_map.hpp>
#include <chrono>
#include "polynomial.hh"

int main()
{

    using clock = std::chrono::steady_clock;

	/* ******************************************** Label and Weight tests ******************************************/

	std::cout << std::boolalpha << "\033[33m" << "\n\t****** Label tests ******\n" << "\033[0m" << std::endl;

	/* int labels tests */
	std::cout << "\n\033[4m" << "Int labels:\n\n" << "\033[0m";
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
	std::cout << "\n\033[4m" <<"String labels:\n\n" << "\033[0m";
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
	std::cout << "\n\033[4m" <<"Int weights:\n\n" << "\033[0m";
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
	std::cout << "\n\033[4m" <<"Bool weights:\n\n" << "\033[0m";
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



    /* ******************************************** BENCHMARK ******************************************/

    std::chrono::duration<double, std::nano> d;

    std::cout << std::boolalpha << "\033[33m" << "\n\t****** THE REAL STUFF ******\n" << "\033[0m" << std::endl;

    /* Ordered vector */
    std::cout << "\n\033[4m" <<"Ordered vector:\n\n" << "\033[0m";

	Label<std::string> l("x");
	Label<std::string> l2("y");
	Label<std::string> l3("z");
	Label<std::string> l4("xy");

	Weight<int> w5(2);
	Weight<int> w6(3);
	Weight<int> w7(4);
	Weight<std::string> w8("toto");
	auto poly = new Polynomial<std::string, int, std::vector, std::pair<Label<std::string>, Weight<int>>>();
	poly->add_monomial(l, w5);
	poly->add_monomial(l2, w6);
	poly->add_monomial(l3, w7);
	std::cout << "\tp1 = " << *poly << std::endl;

	auto p = new Polynomial<std::string, int, std::vector, std::pair<Label<std::string>, Weight<int>>>();
	p->add_monomial(l, w5);
	p->add_monomial(l2, w6);
	p->add_monomial(l3, w7);
    std::cout << "\tp2 = " << *p << std::endl;

    clock::time_point p1_addition_start = clock::now();
    *poly = *poly + *p;
    clock::time_point p1_addition_end = clock::now();
	std::cout << "\tp1 += p2 = " << *poly << std::endl;

    clock::time_point p1_multi_start = clock::now();
	*poly = *poly * *p;
    clock::time_point p1_multi_end = clock::now();
	std::cout << "\tp1 *= p2 = " << *poly << std::endl;


    /* flat_map */
    std::cout << "\n\033[4m" <<"Flat map:\n\n" << "\033[0m";

    auto p2 = new Polynomial<std::string, int, boost::container::flat_map, Label<std::string>, Weight<int>,
								myless<Label<std::string>>>();
	p2->add_monomial(l, w5);
    p2->add_monomial(l2, w6);
    p2->add_monomial(l3, w7);
    std::cout << "\tp3 = " << *p2 << std::endl;
	auto p3 = new Polynomial<std::string, int,
													boost::container::flat_map,
													Label<std::string>,
													Weight<int>,
													myless<Label<std::string>>>();
	p3->add_monomial(l, w5);
    p3->add_monomial(l2, w6);
    p3->add_monomial(l3, w7);
    std::cout << "\tp4 = " << *p3 << std::endl;

    clock::time_point p2_addition_start = clock::now();
	*p2 = *p2 + *p3;
    clock::time_point p2_addition_end = clock::now();
	std::cout << "\tp3 += p4 = " << *p2 << std::endl;

    clock::time_point p2_multi_start = clock::now();
	*p2 = *p2 * *p3;
    clock::time_point p2_multi_end = clock::now();
    std::cout << "\tp3 *= p4 = " << *p2 << std::endl;


    d = p1_addition_end - p1_addition_start;
    double p1_addition = d.count();
    d = p1_multi_end - p1_multi_start;
    double p1_multi = d.count();
    d = p2_addition_end - p2_addition_start;
    double p2_addition = d.count();
    d = p2_multi_end - p2_multi_start;
    double p2_multi = d.count();
    std::cout << "\n\033[4m" <<"Addition:" << "\033[0m" << " Ordered vector:"
                << p1_addition << " ns" << std::endl;
    std::cout << "\t\tFlat_map:" << p2_addition << " ns" << std::endl;
    std::cout << "\n\033[4m" <<"Multi:" << "\033[0m" << " Ordered vector:"
    << p1_multi << " ns" << std::endl;
    std::cout << "\t\tFlat_map:" << p2_multi << " ns" << std::endl;

}
