#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/unordered_map.hpp>
#include <iostream>
using namespace boost;
using namespace std;
BOOST_AUTO_TEST_CASE(unorderedMap)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Case:unorderedMap" << endl;
	using namespace boost::assign;
	unordered_map<int,string> um = (map_list_of(1,"one")(2,"two")(3,"three"));
	um.insert(make_pair(10,"ten"));
	um[11] = "eleven";
	um[12] = "twelve";

	unordered_map<int,string>::iterator p = um.begin();
	for(p;p!=um.end();++p)
	{
		cout << p->first << "-" << p->second << ",";
	}

}