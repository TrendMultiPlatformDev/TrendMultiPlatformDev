// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
#include <boost/asio/ip/address.hpp>

BOOST_AUTO_TEST_CASE( asio_test ) 
{
	int i = 1;
	BOOST_ASSERT(i == 1);
}

BOOST_AUTO_TEST_CASE( asio_ip_test )
{
	boost::asio::ip::address addr = boost::asio::ip::address::from_string("127.0.0.1");
	BOOST_ASSERT( addr.is_loopback() == true );
}
