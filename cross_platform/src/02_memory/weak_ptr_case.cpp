#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/smart_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <iostream>

using namespace boost;

class self_shared : public enable_shared_from_this<self_shared>
{
public:
	self_shared(int n):x(n){};
	int x;
	void print(){
		std::cout << "self shared:" << x << std::endl;
	}
};

class node{
public:
	~node(){
		std::cout << "deleted ***********" << std::endl;
	}
	int x;
	typedef weak_ptr<node> ptr_type;
	ptr_type next;
};

BOOST_AUTO_TEST_SUITE(t_weak_ptr)

BOOST_AUTO_TEST_CASE(t_weak_ptr_case1){
	shared_ptr<int> sp(new int(10));
	BOOST_ASSERT(sp.use_count() == 1 && "sp use count should be 1");

	weak_ptr<int> wp(sp);
	BOOST_ASSERT(wp.use_count() == 1 && "wp use count should be 1");

	if(!wp.expired()){
		shared_ptr<int> sp2 = wp.lock();
		*sp2 = 100;
		BOOST_ASSERT(sp2.use_count() == 2 && "sp2 use count should be 2");
		BOOST_ASSERT(*sp == 100 && "sp should be 100");
	}

	BOOST_ASSERT(wp.use_count() == 1 && "wp use count should be 1");
	wp.reset();
	BOOST_ASSERT(wp.expired() && "wp should have expired");
	BOOST_ASSERT(!wp.lock() && "wp lock should be null");
}

BOOST_AUTO_TEST_CASE(t_weak_ptr_case2){
	shared_ptr<self_shared> sp = make_shared<self_shared>(314);
	sp->print();

	shared_ptr<self_shared> p = sp->shared_from_this();
	p->x = 100;
	p->print();
	std::cout << "p use count" << sp.use_count() << std::endl;
}


BOOST_AUTO_TEST_CASE(t_weak_ptr_case3){
	shared_ptr<node> p1 = make_shared<node>();
	shared_ptr<node> p2 = make_shared<node>();

	p1->next = p2;
	p2->next = p1;

	BOOST_ASSERT(p1.use_count() == 1);
	BOOST_ASSERT(p2.use_count() == 1);

	if(!p1->next.expired()){
		shared_ptr<node> p3 = p1->next.lock();
	}
}

BOOST_AUTO_TEST_SUITE_END()


