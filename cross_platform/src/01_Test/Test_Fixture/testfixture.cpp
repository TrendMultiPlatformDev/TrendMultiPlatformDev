#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/assign.hpp>
#include <iostream>
#include <vector>
using namespace boost;

// global fixture class
struct global_fixture
{
	global_fixture()
	{
		std::cout << "global setup" << std::endl;
	}
	~global_fixture()
	{
		std::cout << "global teardown" << std::endl;
	}
};

// define the global fixture
BOOST_GLOBAL_FIXTURE(global_fixture);

//test suite class
struct assign_fixture
{
	assign_fixture()
	{
		std::cout << "suit setup" << std::endl;
	}
	~assign_fixture()
	{
		std::cout << "suit teardown" << std::endl;
	}

	std::vector<int> v; // all test cases can use this variable	
};

//
BOOST_FIXTURE_TEST_SUITE(s_assign, assign_fixture);

BOOST_AUTO_TEST_CASE(t_assigna1)
{
	using namespace boost::assign;

	v += 1,2,3,4;
	BOOST_CHECK_EQUAL(v.size(), 4);
	BOOST_CHECK_EQUAL(v[2],3);
}

BOOST_AUTO_TEST_CASE(t_assigna2)
{
	using namespace boost::assign;
	push_back(v)(10)(20)(30);

	BOOST_CHECK_EQUAL(v.empty(),false);
	BOOST_CHECK_LT(v[0],v[1]);
}

BOOST_AUTO_TEST_SUITE_END();
