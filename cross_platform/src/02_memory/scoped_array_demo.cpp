#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/smart_ptr.hpp>
#include <algorithm>

using namespace std;
using namespace boost;

BOOST_AUTO_TEST_SUITE(t_scoped_array)

BOOST_AUTO_TEST_CASE(t_scoped_array_case){
	int *arr = new int [100];
	scoped_array<int> sa(arr);

	fill_n(&sa[0], 100, 5);
	sa[10] = sa[20] + sa[30];
	
	BOOST_ASSERT(sa[10] == 10 && "fill_n failed");
}

BOOST_AUTO_TEST_SUITE_END()