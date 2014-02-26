#define BOOST_TEST_MAIN
#include <boost/test/impl/execution_monitor.ipp>
#include <boost/test/impl/debug.ipp>
#include <iostream>
using namespace boost;

//self define exception class
struct my_error
{
	int err_code;
	my_error(int cc):err_code(cc)
	{

	}
};

void translate_my_error(const my_error &e)
{
	std::cout << "my err=" << e.err_code << std::endl;
}

int f()
{
	std::cout << "f execute." << std::endl;
	throw my_error(100);
	return 10;
}

int main()
{
	execution_monitor em; // monitor object

	//
	em.register_exception_translator<my_error>(&translate_my_error);

	try
	{
		em.execute(unit_test::callback0<int>(f)); // monitor f 
	}
	catch(execution_exception &e)
	{
		std::cout << "execution_exception" << std::endl;
		std::cout << e.what().begin() << std::endl; //
	}
}