#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>
#include <boost/dynamic_bitset.hpp>
#include <iostream>
using namespace boost;
using namespace std;

BOOST_AUTO_TEST_CASE(dynamicBitset)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Case:dynamicBitset" << endl;
	//initial
	dynamic_bitset<> db1(5,BOOST_BINARY(11011));
	cout << db1 << endl;
	dynamic_bitset<> db2;//empty bistset
	dynamic_bitset<>::size_type xx = db1.find_first();
	cout << xx <<endl;

	//resize
	db2.resize(10,true);//10 bits whose value are 1
	cout << db2 << endl;
	db2.resize(5);
	cout << db2 << endl;
	//db.resize(0);//db.clear()
	
	//and or operation
	BOOST_ASSERT(db1.size() == db2.size());
	cout << "db1 and db2 is: " << (db1 ^ db2) << endl;
	cout << "db1 or db2 is: " << (db1 | db2) << endl;

	//conversion
	cout << "db1 to ulong is: " << db1.to_ulong() << endl;
}

BOOST_AUTO_TEST_CASE(findPrime)
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Case:findPrime" << endl;
	int n = 10;
	dynamic_bitset<> db(n);
	db.set();//set all bits to 1;
	cout << dynamic_bitset<>::npos << endl;
	
	for(dynamic_bitset<>::size_type i = db.find_next(1);
		i != dynamic_bitset<>::npos;
		i = db.find_next(i))
	{
		for(dynamic_bitset<>::size_type j = db.find_next(i);
			j != dynamic_bitset<>::npos;
			j = db.find_next(j))
		{
			if(j % i == 0)
			{
				db[j] = 0;
			}
		}
	}

	for(dynamic_bitset<>::size_type i = db.find_next(2);
		i != dynamic_bitset<>::npos;
		i = db.find_next(i))
	{
		cout << i << ", ";
	}
}