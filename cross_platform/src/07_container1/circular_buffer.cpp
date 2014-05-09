#define BOOST_TEST_INCLUDED
#include <boost/test/unit_test.hpp>
#include <boost/circular_buffer.hpp>
#include <boost/assign/list_of.hpp>
#include <iostream>
using namespace boost;
using namespace std;


template<typename T>
void print(circular_buffer<T>& cb)
{
	typename circular_buffer<T>::iterator it = cb.begin();
	for(it;it!=cb.end();++it)
	{
		cout << *it << ",";
	}
	cout << endl;
}



BOOST_AUTO_TEST_CASE(circularBuffer)
{
	//loop queue
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "Case:circularBuffer" << endl;
	circular_buffer<int> cb(5);
	BOOST_ASSERT(cb.empty());//no data in cb

	cb.push_front(2);
	cb.push_back(1);
	BOOST_ASSERT(cb.front() == 2);
	cb.insert(cb.begin(), 3);

	cb.pop_front();
	BOOST_ASSERT(cb.size() == 2);

	//compare operation
	using namespace boost::assign;
	circular_buffer<int> cb1 = (list_of(1),2,3);
	circular_buffer<int> cb2 = (list_of(3),4,5);
	circular_buffer<int> cb3 = cb1;

	BOOST_ASSERT(cb1 < cb2);
	BOOST_ASSERT(cb1 == cb3);

	circular_buffer<int> cbInt = (list_of(1),2,3);
	print(cbInt);//1,2,3
	
	cbInt.push_back(4);
	print(cbInt);//2,3,4

	cbInt.push_back(5);
	print(cbInt);//3,4,5

	cbInt.pop_front();
	print(cbInt);
}

BOOST_AUTO_TEST_CASE(circularBufferSpaceOptimized)
{
	using namespace boost::assign;

	circular_buffer_space_optimized<int> cb(10);
	cb.push_back(1);

	assert(cb.size() == 1);
	assert(cb.capacity() == 10);

	cb.resize(100,10);
	assert(cb.size() == cb.capacity());
}
