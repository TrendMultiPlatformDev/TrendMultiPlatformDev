// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/address.hpp>

BOOST_AUTO_TEST_SUITE(s_asio_ip);

BOOST_AUTO_TEST_CASE( asio_ip_testcase1 ) 
{
	boost::asio::ip::address addr = boost::asio::ip::address::from_string("127.0.0.1");
	BOOST_ASSERT( addr.is_loopback() == true );
}

BOOST_AUTO_TEST_CASE( asio_ip_testcase2 )
{
	boost::asio::ip::address addr = boost::asio::ip::address_v4::loopback();
	BOOST_ASSERT( addr.to_string() == "127.0.0.1" );
}

BOOST_AUTO_TEST_SUITE_END()