#define BOOST_TEST_MODULE test

#include <iostream>
#include <vector>
#include <map>

#include <boost/utility.hpp>
#include <boost/assert.hpp>
#include <boost/algorithm/minmax.hpp>
#include <boost/cstdint.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <boost/foreach.hpp>
#include <boost/tuple/tuple.hpp>
#include <boost/algorithm/minmax_element.hpp>

using namespace boost;
using namespace boost::assign;
using namespace std;

#define foreach BOOST_FOREACH
#define reverse_foreach BOOST_REVERSE_FOREACH

BOOST_AUTO_TEST_CASE(foreach_case)
{
	vector<int> v= list_of(1)(2)(3);

	BOOST_FOREACH(int x, v)
	{
		BOOST_ASSERT(x == 1 || x == 2 || x == 3);
	}

	BOOST_REVERSE_FOREACH(int x, v)
	{
		BOOST_ASSERT(x == 1 || x == 2 || x == 3);
	}

	foreach(int x, v)
	{
		BOOST_ASSERT(x == 1 || x == 2 || x == 3);
	}

	reverse_foreach(int &x, v)
	{
		BOOST_ASSERT(x == 1 || x == 2 || x == 3);
		x = 4;
	}

	foreach(int x, v)
	{
		BOOST_ASSERT(x == 4);
	}

	map<int, int> m = map_list_of(1, 2)(2, 3);

	//c++ 11 support 
	foreach(auto x, m)
	{
		BOOST_ASSERT((x.first == 1 && x.second == 2) || (x.first == 2 && x.second == 3));
	}
	
	foreach(BOOST_IDENTITY_TYPE((pair<int, int>)) x, m)
	{
		BOOST_ASSERT((x.first == 1 && x.second == 2) || (x.first == 2 && x.second == 3));
	}
}

BOOST_AUTO_TEST_CASE(mimax_case)
{
	auto x =boost::minmax(1, 2);
	BOOST_ASSERT(x.get<1>() == 2); 
	BOOST_ASSERT(x.get<0>() == 1);

	int a, b;
	boost::tie(a, b) = boost::minmax(3,4);
	BOOST_ASSERT(a == 3);
	BOOST_ASSERT(b == 4);
}

BOOST_AUTO_TEST_CASE(mimax_element_case)
{
	vector<int> v = list_of(2)(4)(8)(32)(64)(128)(256)(512)(1024);
	auto x = boost::minmax_element(v.begin(), v.end());
	BOOST_ASSERT(*x.first == 2);
	BOOST_ASSERT(*x.second == 1024);
}