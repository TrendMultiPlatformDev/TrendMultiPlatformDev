#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/smart_ptr.hpp>
#include <stdlib.h>
using namespace boost;

//test suite s_smart_prt
BOOST_AUTO_TEST_SUITE(s_smart_ptr);

//test case t_scoped_ptr
BOOST_AUTO_TEST_CASE(t_scoped_ptr)
{
	scoped_ptr<int> p(new int(874));
	BOOST_CHECK(p); // p is not NULL
	BOOST_CHECK_EQUAL(*p, 874); //check the value

	p.reset(); // reset p;
	BOOST_CHECK(p == 0); // NULL
}

BOOST_AUTO_TEST_CASE(t_shared_ptr)
{
	shared_ptr<int> p(new int(100));

	BOOST_CHECK(p); // p is not NULL
	BOOST_CHECK_EQUAL(*p, 100); // check  the value
	BOOST_CHECK_EQUAL(p.use_count(),1); // the count of reference

	shared_ptr<int> p2 = p;
	BOOST_CHECK_EQUAL(p, p2); // 
	BOOST_CHECK_EQUAL(p2.use_count(), 2);// 2

	*p2 = 255;
	BOOST_CHECK_EQUAL(*p, 255);
	BOOST_CHECK_GT(*p, 200);
}

// end the test suite
BOOST_AUTO_TEST_SUITE_END()
