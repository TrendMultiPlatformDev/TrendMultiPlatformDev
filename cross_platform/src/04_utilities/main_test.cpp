#include <cstdlib>
#include <string>

#define BOOST_TEST_MODULE test_utilities
#include <boost/test/unit_test.hpp>

#include "singleton.h"

using namespace std;
using namespace trend;

BOOST_AUTO_TEST_CASE(noncopyable) 
{
	SomeLogdPtr logd1 = SomeLogd::GetInstance();
	SomeLogdPtr logd2 = SomeLogd::GetInstance();

	logd1->Log("log from logd1");
	logd2->Log("log from logd2");

	string strLog1 = logd1->GetLog();
	string strLog2 = logd2->GetLog();

	BOOST_ASSERT(strLog1 == strLog2);
	BOOST_ASSERT(strLog1.find("log from logd1") != string::npos);
	BOOST_ASSERT(strLog1.find("log from logd2") != string::npos);
}

