#define BOOST_TEST_MAIN
#include <boost/progress.hpp>
#include <boost/test/unit_test.hpp>
#include <fstream>
using namespace boost;

BOOST_AUTO_TEST_CASE(d_progress_display1){
	std::vector<std::string> v(1000000);
	for(int i = 0; i < 1000000; i++){
		v[i] = "I am a string ";
	}

	std::ofstream fs("./test.txt");

	progress_display pd(v.size());

	for(int i = 0;i < 1000000;i++ ){
		fs << v[i] << std::endl;
		++pd;
	}
}
