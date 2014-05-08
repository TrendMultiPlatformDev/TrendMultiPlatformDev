#include <iostream>

#define BOOST_TEST_MAIN
#include <boost/timer.hpp>
#include <boost/test/unit_test.hpp>

using namespace boost;

BOOST_AUTO_TEST_CASE(d_timer1)
{
	timer t;

	std::cout << "max timespan:"
		<< t.elapsed_max() << "s or " <<t.elapsed_max() / 3600 << "h" <<std::endl;
	std::cout << "min timespan:"
		<< t.elapsed_min() << "s" << std::endl;
	std::cout << "now time elapsed:"
		<< t.elapsed() << "s" << std::endl;
}