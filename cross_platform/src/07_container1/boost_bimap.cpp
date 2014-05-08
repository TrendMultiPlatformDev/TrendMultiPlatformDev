#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>
#include <boost/assign/list_of.hpp>
#include <boost/bimap.hpp>
#include <iostream>
using namespace boost;
using namespace std;



BOOST_AUTO_TEST_CASE(bimapTest)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Case:bimapTest" << endl;
	using namespace boost::bimaps;
	bimap<int,string> bm;
	
	bm.left.insert(make_pair(1,"111"));
	bm.left.insert(make_pair(2,"222"));

	bm.right.insert(make_pair("333",3));
	bm.right.insert(make_pair("444",4));
	
	typedef bimap< int, string > bm_type;
	typedef bm_type::left_map::const_iterator left_const_iterator;
	typedef bimap<int,string>::value_type vt;
	bm.insert(vt(5,"555"));
	for( left_const_iterator pos = bm.left.begin();pos != bm.left.end();++pos)
	{
		cout << "left[" << pos->first << "]="
			 << pos->second << endl;
	}

	bimap<tagged<int, struct id>, tagged<string, struct name>> bmTag;

	bmTag.by<id>().insert(make_pair(1, "samus"));
	bmTag.by<id>().insert(make_pair(2, "adam"));

	bmTag.by<name>().insert(make_pair("link", 10));
	bmTag.by<name>().insert(make_pair("zelda", 11));


	//bm.right.begin()->second = 234;error

}