#define BOOST_TEST_MAIN
#include <iostream>
#include <string>
#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
#include <boost/foreach.hpp>
#include <boost/test/unit_test.hpp>
#include <stdlib.h>

using namespace std;
using namespace boost::property_tree;

//test suite s_smart_prt
BOOST_AUTO_TEST_SUITE(s_pt);
//test case t_tuple_base
BOOST_AUTO_TEST_CASE(t_pt_base)
{
	ptree pt;
	read_xml("conf.xml", pt);

	cout << pt.get<string>("conf.theme") << endl;
	cout << pt.get<int>("conf.clock_style") << endl;
	cout << pt.get<long>("conf.gui") << endl;
	cout << pt.get("cong.no_prop", 100) << endl;

	BOOST_FOREACH(auto& x, pt.get_child("conf.urls")){
		cout << x.second.data() << ",";
	}
	cout << endl;
}

BOOST_AUTO_TEST_CASE(t_pt_slice)
{
	ptree pt;
	read_xml("conf2.xml", pt);
	
	pt.put("conf.theme", "Matrix Reloaded");
	pt.put("conf.clock_style", 12);
	pt.put("cong.gui", 0);
	pt.put("conf.urls.url", "http://www.url6.org");

	write_xml(cout, pt);
}

// end the test suite
BOOST_AUTO_TEST_SUITE_END()