// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
#define BOOST_TEST_MODULE test

#include <boost/test/unit_test.hpp>
#include <boost/asio.hpp>
#include <boost/asio/io_service.hpp>
#include <boost/asio/ip/address.hpp>
#include <boost/asio/ip/tcp.hpp>

using namespace boost::asio;

BOOST_AUTO_TEST_SUITE(s_asio_ip_address)

	BOOST_AUTO_TEST_CASE( asio_ip_testcase1 ) 
	{
		boost::asio::ip::address addr1 = boost::asio::ip::address::from_string("127.0.0.1");
		boost::asio::ip::address addr2 = boost::asio::ip::address_v4::loopback();
		boost::asio::ip::address addr3 = boost::asio::ip::address_v6::loopback();

		BOOST_ASSERT( addr1.is_loopback() == true && 
					  addr2.to_string() == "127.0.0.1" &&
					  addr3.to_string() == "::1" && 
					  addr2 != addr3
					);
	}

	BOOST_AUTO_TEST_CASE( asio_ip_testcase2 )
	{
		boost::asio::ip::address_v4 addr1 = boost::asio::ip::address_v4::from_string("10.64.40.170");
		boost::asio::ip::address addr2 = boost::asio::ip::address::from_string("2620:101:4002:42B:10:64:67:55");

		BOOST_ASSERT( addr1.is_class_a() == true   && 
					  addr1.is_multicast() == false	&&
					  addr1.to_ulong() == 171976874 &&
					  addr2.is_v4() == false && 
					  addr2.is_v6()  == true
					);

	}

BOOST_AUTO_TEST_SUITE_END()		//s_asio_ip_address

BOOST_AUTO_TEST_SUITE(s_asio_endpoint)

	BOOST_AUTO_TEST_CASE( asio_endpoint_testcase1 ) 
	{
		//	default constructor, can be used sometimes for UDP/ICMP sockets
		boost::asio::ip::tcp::endpoint ep1;	 
		//	usually used on server sockets for accepting new connections
		boost::asio::ip::tcp::endpoint ep2(boost::asio::ip::tcp::v4(), 80);
		boost::asio::ip::tcp::endpoint ep3(boost::asio::ip::address::from_string("127.0.0.1"), 80);

		//	connect to a hostname
		boost::asio::io_service service;
		boost::asio::ip::tcp::resolver resolver(service);
		boost::asio::ip::tcp::resolver::query query("www.baidu.com", "80");
		boost::asio::ip::tcp::resolver::iterator iter = resolver.resolve(query);
		boost::asio::ip::tcp::endpoint ep = *iter;
		BOOST_ASSERT( ep.port() == 80 );
	}

BOOST_AUTO_TEST_SUITE_END() // s_asio_endpoint

