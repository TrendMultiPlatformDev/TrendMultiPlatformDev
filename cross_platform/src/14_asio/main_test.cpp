// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( asio_test ) {
	int i = 1;
	BOOST_ASSERT(i == 1);
}


