#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/smart_ptr.hpp>

using namespace boost;

BOOST_AUTO_TEST_SUITE(t_shared_array)

BOOST_AUTO_TEST_CASE(t_shared_array_case1){
	int *p = new int[100];
	shared_array<int> sa(p);
	shared_array<int> sa2 = sa;

	sa[0] = 100;

	BOOST_ASSERT( sa2[0] == 100 && "sa2[0] should equal 100");
}

BOOST_AUTO_TEST_SUITE_END()

