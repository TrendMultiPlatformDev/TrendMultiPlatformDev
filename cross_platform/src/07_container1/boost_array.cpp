#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>
#include <boost/array.hpp>
#include <iostream>
using namespace boost;
using namespace std;

BOOST_AUTO_TEST_CASE(boostarray)
{
	cout << "Case:boostarray" << endl;

	array<int, 10> ar;
	/*
	for (int i=0;i<10;i++)
	{
		cout <<ar[i]<< ",";
	}
	*/
	ar[0] = 1;
	ar.back() = 10;
	BOOST_ASSERT(ar[ar.max_size() - 1] == 10);
	ar.assign(777);
	for (int i=0;i<10;i++)
	{
		cout <<ar[i]<< ",";
	}
	int *p = ar.c_array();
	*(p+5) = 253;
	cout << ar[5] << endl;

	ar.at(8) = 666;
	sort(ar.begin(), ar.end());
}