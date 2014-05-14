#define BOOST_TEST_MAIN
#include <iostream>
#include <string>
#include <boost/multi_array.hpp>

#include <boost/test/unit_test.hpp>
#include <stdlib.h>

using namespace std;
using namespace boost;


//test suite s_smart_prt
BOOST_AUTO_TEST_SUITE(ma_variant);
//test case t_tuple_base
BOOST_AUTO_TEST_CASE(t_ma_base)
{
	multi_array<int, 3> ma (extents[2][3][4]);

	for(int i = 0, v = 0; i < 2; ++i)
		for(int j = 0; j < 3; ++j)
			for(int k = 0; k < 4; ++k)
				ma[i][j][k] = v++;

	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 3; ++j){
			for(int k = 0; k < 4; ++k)
				cout <<	ma[i][j][k] << ",";
			cout << endl;
		}
		cout << endl;
	}

	//cout << ma[2][3][4];
	//Î»ÖÃË÷ÒýÐòÁÐ
	boost::array<size_t, 3> idx = {0, 1, 2};
	//ma(idx) = 10;
	cout << ma(idx);

	BOOST_ASSERT(ma.shape()[0] == 2);
	boost::array<size_t, 3> arr = {4, 3, 2};
	ma.reshape(arr);
	BOOST_ASSERT(ma.shape()[0] == 4);

	ma.resize(extents[2][9][9]);
	BOOST_ASSERT(ma.num_elements() == 2*9*9);
	BOOST_ASSERT(ma.shape()[1] == 9);
}

BOOST_AUTO_TEST_CASE(t_ma_slice)
{
	typedef multi_array<int, 2> ma_type;
	ma_type ma (extents[3][4]);
	for(int i = 0, v = 0; i < 2; ++i)
		for(int j = 0; j < 3; ++j)
				ma[i][j] = v++;

	typedef ma_type::index_range range;
	auto view = ma[indices[range(0,2)][range(0,2)]];

	cout << view.num_elements() << endl;
	for(int i = 0; i < 2; ++i){
		for(int j = 0; j < 2; ++j)
			cout << view[i][j] << ",";
		cout << endl;
	}
	cout << *view.shape() << endl;
}

// end the test suite
BOOST_AUTO_TEST_SUITE_END()