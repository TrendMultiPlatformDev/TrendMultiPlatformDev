#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>
#include <boost/unordered_set.hpp>
#include <boost/assign/list_of.hpp>
#include <iostream>
using namespace boost;
using namespace std;
BOOST_AUTO_TEST_CASE(unorderedSet)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Case:unorderedSet" << endl;
	using namespace boost::assign;
	unordered_set<int> s = (list_of(1),2,3,4,5);
	s.clear();
	cout << s.empty() << endl;
	 
	s.insert(8);
	s.insert(45);
	cout << s.size() << endl;
	cout << *s.find(8) << endl;

	
	unordered_set<int> us1 = list_of(1)(2)(3);
	unordered_set<int> us2 = list_of(3)(2)(1);
	BOOST_ASSERT(us1 == us2);
}