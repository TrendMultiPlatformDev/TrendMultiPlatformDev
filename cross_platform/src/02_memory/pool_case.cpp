#define BOOST_TEST_MAIN

#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/pool/pool.hpp>
#include <boost/pool/object_pool.hpp>
#include <boost/pool/singleton_pool.hpp>
#include <boost/pool/pool_alloc.hpp>
#include <iostream>
#include <vector>

using namespace boost;

struct demo_class{
public:
	int a, b, c;
	demo_class(int x = 1, int y = 2, int z = 3) : a(x), b(y), c(z){}
	~demo_class() {
		std::cout << "**********destory********" << std::endl;
	}
};

struct pool_tag{};
typedef singleton_pool<pool_tag, sizeof(int)> sp1;

BOOST_AUTO_TEST_SUITE(t_pool)

BOOST_AUTO_TEST_CASE(t_pool_case){
	pool<> p1(sizeof(int));
	int *p = static_cast<int*>(p1.malloc());
	if(!p){
		*p = 100;
	}

	BOOST_ASSERT(p1.is_from(p));

	p1.free(p);
	for(int i = 0; i < 100; i++)
		p1.ordered_malloc(10);
}

BOOST_AUTO_TEST_CASE(t_object_pool_case){
	object_pool<demo_class> p1;
	demo_class *p = p1.malloc();
	BOOST_ASSERT(p1.is_from(p));

	BOOST_ASSERT(p->a != 1 || p->b != 2 || p->c !=3);

	p = p1.construct(7, 8, 9);
	BOOST_ASSERT(p->a == 7);

	for(int i = 0; i < 10; i++){
		demo_class *p2 = p1.construct(i, i+1, i+2);
	}

}

BOOST_AUTO_TEST_CASE(t_singleton_pool_case){
	int *p = (int*)sp1::malloc();
	BOOST_ASSERT(sp1::is_from(p));

	sp1::release_memory();
}

BOOST_AUTO_TEST_CASE(t_pool_alloc_case){
	std::vector<int, pool_allocator<int> > v;
	v.push_back(10);
	std::cout << "******size = " << v.size() << std::endl;
	BOOST_ASSERT(v.size() == 1);
}

BOOST_AUTO_TEST_SUITE_END()
