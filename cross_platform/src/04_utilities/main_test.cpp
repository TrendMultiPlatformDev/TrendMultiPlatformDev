#include <cstdlib>
#include <iostream>
#include <string>

#include <boost/optional.hpp>
#include <boost/typeof/typeof.hpp>

#define BOOST_TEST_MODULE test_utilities
#include <boost/test/unit_test.hpp>

#include "singleton.h"

using namespace std;
using namespace trend;

BOOST_AUTO_TEST_CASE(utilities) 
{
	SomeLogd& logd1 = SomeLogd::get_mutable_instance();
	logd1.Log("log from logd1");

	SomeLogd& logd2 = SomeLogd::get_mutable_instance();
	logd2.Log("log from logd2");

	string strLog1 = logd1.GetLog();
	string strLog2 = logd2.GetLog();

	//cout << strLog1;

	BOOST_ASSERT(strLog1 == strLog2);
	BOOST_ASSERT(strLog1.find("log from logd1") != string::npos);
	BOOST_ASSERT(strLog1.find("log from logd2") != string::npos);
}

BOOST_AUTO_TEST_CASE(optional)
{
	boost::optional<int> opInt1;
	boost::optional<int> opInt2(boost::none);

	BOOST_ASSERT(opInt1 == opInt2);

	opInt1 = 256;
	opInt2 = 512;

	BOOST_ASSERT(opInt1);
	BOOST_ASSERT(opInt2);
	BOOST_ASSERT(*opInt1 == 256);
	BOOST_ASSERT(opInt2.get() == 512);
}

BOOST_AUTO_TEST_CASE(assign)
{
	
}
