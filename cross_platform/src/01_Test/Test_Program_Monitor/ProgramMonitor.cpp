#define  BOOST_TEST_MAIN
#include <boost/test/included/prg_exec_monitor.hpp>
#include <iostream>
using namespace boost;

int foo()
{
	throw std::runtime_error("big trouble");
}
int cpp_main( int argc, char* argv[] )
{
	std::cout << "hello world" << std::endl;
	foo();
	return 0;
}
