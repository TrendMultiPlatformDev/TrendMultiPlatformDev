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

	//cout << "type of u8 is: " << typeid(u8).name() << endl;
	BOOST_ASSERT(sizeof(u8) == 1);

	//cout << "type of i16 is: " << typeid(i16).name() << endl;
	//BOOST_ASSERT(sizeof(i16) == 4);
	//cout << sizeof(i16) << endl;

	//cout << "type of i32 is:" << typeid(i32).name() << endl;
	BOOST_ASSERT(sizeof(i32) == 4);
}

BOOST_AUTO_TEST_CASE(integer_case)
{
	//int_fast_t
	int_fast_t<int>::fast a;
	BOOST_ASSERT(sizeof(a) == 4);

	//int_t, uint_t
	int_t<32>::fast b;
	BOOST_ASSERT(sizeof(b) == 4);

	uint_t<15>::fast c;
	BOOST_ASSERT(sizeof(c) == 2);

	//int_max_value_t, int_min_value_t,uint_value_t
	int_max_value_t<65536>::fast d;
	BOOST_ASSERT(sizeof(d) == 4);

	int_min_value_t<-65536>::fast e;
	BOOST_ASSERT(sizeof(e) == 4);

	uint_value_t<33000>::fast f;
	BOOST_ASSERT(sizeof(f) == 2);
}

BOOST_AUTO_TEST_CASE(crc_case)
{
	crc_32_type crc32;
	//cout << hex;
	//cout << crc32.checksum() << endl;

	crc32.process_byte('a');
	//cout << "checksum: " << crc32.checksum() << endl;
	//cout << "operator: " << crc32() << endl;

	crc32.process_bytes("0123456789", 10);
	//cout << crc32.checksum() << endl;

	char szCh[] = "0123456789";
	crc32.reset();

	crc32.process_block(szCh, szCh + 10);
	//cout <<crc32.checksum() << endl;

	crc32.reset();
	string str = "1234567890";
	//cout << for_each(str.begin(), str.end(), crc32)() << endl;
	//cout << "last:" << crc32() << endl;
}


BOOST_AUTO_TEST_CASE(random_case)
{
	mt19937 rng(time(0));
	cout << "min & max of random: " << mt19937::min() << "<->" << mt19937::max() << endl;
	for (int i=0; i<5; ++i)
	{
		cout << rng() << ",";
	}
	cout << endl;

	uniform_int<> ui(0, 255);
	for (int i=0; i<5; ++i)
	{
		cout << ui(rng) << ",";
	}
	cout << endl;

	uniform_01<> u01;
	for (int i=0; i<5; ++i)
	{
		cout << u01(rng) << ",";
	}
	cout << endl;
}