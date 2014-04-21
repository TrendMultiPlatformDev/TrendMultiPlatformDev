#define BOOST_TEST_MAIN
#include <iostream>
#include <string>
#include <boost/variant.hpp>

#include <boost/test/unit_test.hpp>
#include <stdlib.h>

using namespace std;
using namespace boost;

typedef variant<int, double, string> var_t;

//test suite s_smart_prt
BOOST_AUTO_TEST_SUITE(s_variant);
//test case t_tuple_base
BOOST_AUTO_TEST_CASE(t_variant_base)
{
	var_t v;

	BOOST_CHECK_EQUAL(v.type(), typeid(int));
	BOOST_CHECK_EQUAL(v.which(), 0);

	v = "boost";
	cout << *get<string>(&v) << endl;
	BOOST_ASSERT(*get<string>(&v) == "boost");

	try{
		cout << get<double>(v) << endl;
	}catch(bad_get &){
		cout << "bad get" << endl;
	}
}

// end the test suite
BOOST_AUTO_TEST_SUITE_END()