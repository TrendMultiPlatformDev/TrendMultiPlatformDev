// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
#include <cstdlib>
#include <exception>
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include <boost/assign.hpp>
#include <boost/config/suffix.hpp>
#include <boost/current_function.hpp>
#include <boost/exception/all.hpp>
#include <boost/optional.hpp>
#include <boost/typeof/typeof.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/format.hpp>
#include <boost/tokenizer.hpp>
#include <boost/xpressive/xpressive_dynamic.hpp>
#include <boost/foreach.hpp>

#define BOOST_TEST_MODULE test_utilities
#include <boost/test/unit_test.hpp>

using namespace std;
using namespace boost;
using namespace boost::xpressive;

BOOST_AUTO_TEST_CASE( lexical_test ) {

	BOOST_ASSERT(lexical_cast<int>("100") == 100);
	BOOST_ASSERT(lexical_cast<double>("3.14159") == 3.14159);
	BOOST_ASSERT(lexical_cast<string>(456) == "456");
	try
	{
		int y = lexical_cast<int>("0x100"); // cause error
	}
	catch (bad_lexical_cast& e)
	{
		cout << "error:" << e.what() << endl;
	}
}

BOOST_AUTO_TEST_CASE( format_test ) {
	format fmt1 = format("%s:%d+%d=%d\n") %"sum" % 1 % 2 % (1+2);
	//cout << fmt1.str();
	BOOST_ASSERT(fmt1.str() == string("sum:1+2=3\n"));
	format fmt2 ("(%1% + %2%) * %2% = %3%\n");
	fmt2 % 2 % 5;
	fmt2 % ((2+5) * 5);
	//cout << fmt2.str();
	BOOST_ASSERT(fmt2.str() == string("(2 + 5) * 5 = 35\n"));
}

BOOST_AUTO_TEST_CASE( string_algo_test ) {

}

BOOST_AUTO_TEST_CASE( tokenizer_test ) {
	string str1 ("Life is a struggle :-)");
	tokenizer<> tok1(str1);
	BOOST_FOREACH(auto x, tok1) {	cout << " [" << x << "] ";}
	cout << endl;

	string str2 ("100,0,0,81abcff,AndroidOS_DroidRooter.ZA,400");
	escaped_list_separator<char> sep2;
	tokenizer<escaped_list_separator<char>> tok2(str2, sep2);
	BOOST_FOREACH(auto x, tok2) {	cout << " [" << x << "] ";}
	cout << endl;

	string str3 ("3.14159265358979");
	int offsets [] = {2,3,4};
	offset_separator sep3(offsets, offsets +3);
	tokenizer<offset_separator> tok3(str3, sep3);
	BOOST_FOREACH(auto x, tok3) {	cout << " [" << x << "] ";}
	cout << endl;
}

BOOST_AUTO_TEST_CASE( xpressive_test ) {
	cregex reg1 = cregex::compile("a.c");
	BOOST_ASSERT( regex_match("abc", reg1) == true );
	BOOST_ASSERT( regex_match("a+c", reg1) == true );

	BOOST_ASSERT( regex_match("ac", reg1) == false );
	BOOST_ASSERT( regex_match("abd", reg1) == false );

	cregex reg2 = cregex::compile("\\d{6}(1|2)\\d{3}(0|1)\\d[0-3]\\d\\d{3}(X|\\d)",icase);
	BOOST_ASSERT( regex_match("99955519700101999x", reg2) == true );
	BOOST_ASSERT( regex_match("99955519700101999Z", reg2) == false );

	char* str3 = ("Life-is a struggle :-)");
	cregex reg3 = cregex::compile("(Life)-(.{4})", icase);
	cmatch what;
	BOOST_ASSERT( regex_search(str3, what, reg3) == true );
}

