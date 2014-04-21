#define BOOST_TEST_MAIN
#include <iostream>
#include <string>
#include <boost/any.hpp>
#include <boost/make_shared.hpp>
#include <boost/test/unit_test.hpp>
#include <stdlib.h>

using namespace boost;

template<typename T> struct any_print;
template<typename T>
struct any_print<T>{
	void operator()(any &a)
	try{
		cout << *any_cast<T>(&a) << endl;
	}catch(bad_any_cast &){
		cout << "print error" << endl;
	}
};

template<typename T>
struct any_print<shared_ptr<T>>{
	void operator()(any &a)
	try{
		cout << **any_cast<shared_ptr<T>>(&a) << endl;
	}catch(bad_any_cast &){
		cout << "print error" << endl;
	}
};
//test suite s_smart_prt
BOOST_AUTO_TEST_SUITE(s_any);
//test case t_tuple_base
BOOST_AUTO_TEST_CASE(t_any_base)
{
	any a;
	char* str = "boost";

	a = str;
	any_print<char*>()(a);

	a = 10;
	any_print<int>()(a);

	shared_ptr<std::string> ps = make_shared<std::string>("hello");
	a = ps;
	any_print<shared_ptr<std::string>>()(a);
}

// end the test suite
BOOST_AUTO_TEST_SUITE_END()