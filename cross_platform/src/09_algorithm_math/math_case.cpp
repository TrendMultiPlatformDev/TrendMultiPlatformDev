#include <boost/integer_traits.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/integer.hpp>
#include <boost/crc.hpp>
#include <boost/random.hpp>

using namespace std;
using namespace boost;


BOOST_AUTO_TEST_CASE(integer_traits_case)
{
	BOOST_ASSERT(integer_traits<int>::const_max == 2147483647);
	BOOST_ASSERT(integer_traits<bool>::const_min == 0);
	BOOST_ASSERT(integer_traits<long>::is_signed == true);
}

BOOST_AUTO_TEST_CASE(cstdint_case)
{
	uint8_t u8;
	int_fast16_t i16;
	int_least32_t i32;

	u8 = 255;
	i16 = 65534;
	i32 = 2147483646;

	BOOST_CHECK_EQUAL(typeid(u8).name(), "unsigned char");
	BOOST_ASSERT(sizeof(u8) == 1);
	BOOST_CHECK_EQUAL(typeid(i16).name(), "int");
	BOOST_ASSERT(sizeof(i16) == 4);
	BOOST_CHECK_EQUAL(typeid(i32).name(), "int");
	BOOST_ASSERT(sizeof(i32) == 4);
}

BOOST_AUTO_TEST_CASE(integer_case)
{
	//int_fast_t
	int_fast_t<int>::fast a;
	BOOST_CHECK_EQUAL(typeid(a).name(), "int");

	//int_t, uint_t
	int_t<32>::fast b;
	BOOST_CHECK_EQUAL(typeid(b).name(), "int");

	uint_t<15>::fast c;
	BOOST_CHECK_EQUAL(typeid(c).name(), "unsigned short");

	//int_max_value_t, int_min_value_t,uint_value_t
	int_max_value_t<65536>::fast d;
	BOOST_CHECK_EQUAL(typeid(d).name(), "int");

	int_min_value_t<-65536>::fast e;
	BOOST_CHECK_EQUAL(typeid(e).name(), "int");

	uint_value_t<33000>::fast f;
	BOOST_CHECK_EQUAL(typeid(f).name(), "unsigned short");
}

BOOST_AUTO_TEST_CASE(crc_case)
{
	crc_32_type crc32;
	cout << hex;
	cout << crc32.checksum() << endl;

	crc32.process_byte('a');
	cout << "checksum: " << crc32.checksum() << endl;
	cout << "operator: " << crc32() << endl;

	crc32.process_bytes("0123456789", 10);
	cout << crc32.checksum() << endl;

	char szCh[] = "0123456789";
	crc32.reset();

	crc32.process_block(szCh, szCh + 10);
	cout <<crc32.checksum() << endl;

	crc32.reset();
	string str = "1234567890";
	cout << for_each(str.begin(), str.end(), crc32)() << endl;
	cout << "last:" << crc32() << endl;
}


BOOST_AUTO_TEST_CASE(random_case)
{
	mt19937 rng(time(0));
	cout << mt19937::min() << "<->" << mt19937::max() << endl;
	cout << endl;
	for (int i=0; i<10; ++i)
	{
		cout << rng() << ",";
	}
	cout << endl;
	uniform_int<> ui(0, 255);
	for (int i=0; i<10; ++i)
	{
		cout << ui(rng) << ",";
	}
	cout << endl;

	uniform_01<> u01;
	for (int i=0; i<10; ++i)
	{
		cout << u01(rng) << ",";
	}
}