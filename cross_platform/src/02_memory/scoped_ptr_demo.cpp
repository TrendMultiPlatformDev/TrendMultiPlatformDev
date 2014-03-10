#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/smart_ptr.hpp>
#include <iostream>
using namespace std;
using namespace boost;

struct posix_file
{
	posix_file(const char* file_name){
		cout << "open file:" << file_name << endl;
	}
	~posix_file(){
		cout << "close file" <<  endl;
	}
};

BOOST_AUTO_TEST_SUITE(t_scoped_ptr)

BOOST_AUTO_TEST_CASE(t_scoped_ptr_case){
	scoped_ptr<int> p (new int);
	
	if(p){
		*p = 100;
		cout << *p << endl;
	}
	
	p.reset();
	
	BOOST_ASSERT(p == 0 && "scoped_ptr is not null");
	
	scoped_ptr<posix_file> fp(new posix_file("/tmp/a.txt"));
}

BOOST_AUTO_TEST_SUITE_END()