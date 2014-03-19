#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <boost/assign.hpp>
#include <boost/optional.hpp>
#include <boost/typeof/typeof.hpp>

#define BOOST_TEST_MODULE test_utilities
#include <boost/test/unit_test.hpp>

#include "singleton.h"
#include "point.h"

using namespace std;
using namespace trend;
using namespace boost::assign;

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
	vector<int> vi;
	vi += 0,1,2,3,4,5;

	BOOST_ASSERT(vi.size() == 6);
	BOOST_ASSERT(vi[3] == 3);
	BOOST_ASSERT(vi[5] == 5);

	map<int, string> mapIntStr;
	BOOST_AUTO(pair1, make_pair(0, "Hello"));
	BOOST_AUTO(pair2, make_pair(99, "World"));

	mapIntStr += pair1, pair2;

	BOOST_ASSERT(mapIntStr[0] == "Hello");
	BOOST_ASSERT(mapIntStr[99] == "World");

	map<string, string> mapStrStr1 = map_list_of
		("test", "²âÊÔ")
		("haha", "¹þ¹þ");

	BOOST_ASSERT(mapStrStr1["test"] == "²âÊÔ");
	BOOST_ASSERT(mapStrStr1["haha"] == "¹þ¹þ");

	map<string, string> mapStrStr2 = map_list_of
		("test2", "²âÊÔ2")
		("haha2", "¹þ¹þ2");

	boost::swap(mapStrStr1, mapStrStr2);

	BOOST_ASSERT(mapStrStr1["test2"] == "²âÊÔ2");
	BOOST_ASSERT(mapStrStr1["haha2"] == "¹þ¹þ2");
	BOOST_ASSERT(mapStrStr2["test"] == "²âÊÔ");
	BOOST_ASSERT(mapStrStr2["haha"] == "¹þ¹þ");
}

BOOST_AUTO_TEST_CASE(operators)
{
	Point p1(1, 2, 3);
	Point p2(1, 2, 3);
	Point p3(2, 3, 4);

	BOOST_ASSERT(p1 == p2);
	BOOST_ASSERT(p1 != p3);
	BOOST_ASSERT(p1 <= p2);
	BOOST_ASSERT(p1 < p3);
	BOOST_ASSERT(p3 > p2);

	Point p4 = p3 - p2;
	Point p5 = p1 + p3;

	/*p4.print();
	p5.print();*/
	BOOST_ASSERT(p4 == Point(1, 1, 1));
	BOOST_ASSERT(p5 == Point(3, 5, 7));
}

