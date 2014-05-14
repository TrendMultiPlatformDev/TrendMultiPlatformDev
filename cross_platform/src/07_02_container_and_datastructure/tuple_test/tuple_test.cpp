#define BOOST_TEST_MAIN
#include <iostream>
#include <string>
#include <boost/tuple/tuple.hpp>
#include <boost/tuple/tuple_comparison.hpp>
#include <boost/tuple/tuple_io.hpp>
#include <boost/test/unit_test.hpp>
#include <stdlib.h>

using namespace std;
using namespace boost;

typedef boost::tuple<int, double, string> my_tuple;

//test suite s_smart_prt
BOOST_AUTO_TEST_SUITE(s_tuple);
//test case t_tuple_base
BOOST_AUTO_TEST_CASE(t_tuple_base)
{
	my_tuple t1 = boost::make_tuple(3, 100.0, string("boost"));
	my_tuple t2 = boost::make_tuple(3, 200.0, string("hello"));

	BOOST_CHECK_EQUAL(t1.get<0>(), 3);
	BOOST_CHECK_LT(t1, t2);

	my_tuple t3(t2);
	BOOST_ASSERT(t2 == t3);
}

//test case t_tuple_io
BOOST_AUTO_TEST_CASE(t_tuple_io)
{
	my_tuple t1(3, 10.0, "boost");
	my_tuple t2;
	
	cout << t1 << endl;
	cout << "please input tuple:" << endl;
	cin >> t2;

	cout << t2 << endl;
}

//test case t_tuple_io
BOOST_AUTO_TEST_CASE(t_tuple_tie)
{
	int i; double d; string s;
	boost::tie(i, d, s) = boost::make_tuple(1, 2.0, "string");
	cout << s << endl;
	
	BOOST_ASSERT(s == "string");
}

// end the test suite
BOOST_AUTO_TEST_SUITE_END()