#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/smart_ptr.hpp>
#include <iostream>
#include <string>
#include <vector>

using namespace boost;

class shared{
private:
	shared_ptr<int> p;
public:
	shared(shared_ptr<int> sp) : p(sp)	{}
	void print(){
		std::cout << "count:" << p.use_count() << "value = " << *p <<std::endl;
	}
	int getUseCount() { return p.use_count(); }
	int operator *() const { return *p; }
};


void print_info(shared_ptr<int> p){
	std::cout << "count:" << p.use_count() << "value = " << *p <<std::endl;
}

BOOST_AUTO_TEST_SUITE(t_shared_ptr)

BOOST_AUTO_TEST_CASE(t_shared_ptr_case1){
	std::cout<< "**************t_shared_ptr_case1**************" <<std::endl;
	shared_ptr<int> sp(new int(10));
	BOOST_ASSERT(sp.unique() && "sp in not unique");

	shared_ptr<int> sp2 = sp;
	BOOST_ASSERT(sp == sp2 && sp.use_count() == 2);

	*sp2 = 100;
	BOOST_ASSERT(*sp == 100 && "*sp in not equal 100");

	sp.reset();
	BOOST_ASSERT(!sp && "sp i no reset");

	BOOST_ASSERT(sp2.unique() && "sp2 is not unique");
	std::cout<< "**************t_shared_ptr_case1**************" <<std::endl;
}

BOOST_AUTO_TEST_CASE(t_shared_ptr_case2){
	std::cout<< "**************t_shared_ptr_case2**************" <<std::endl;
	shared_ptr<int> p(new int(100));
	shared s1(p), s2(p);

	s1.print();
	BOOST_ASSERT(s1.getUseCount() == 3 && "Error: useCount should be 2");
	s2.print();
	BOOST_ASSERT(s2.getUseCount() == 3 && "Error: useCount should be 3");

	*p = 20;
	print_info(p);

	BOOST_ASSERT(*s1 == 20 && "*s1 should be 20");
	BOOST_ASSERT(*s2 == 20 && "*s2 should be 20");
	s1.print();
	s2.print();
	std::cout<< "**************t_shared_ptr_case2**************" <<std::endl;
}

BOOST_AUTO_TEST_CASE(t_shared_ptr_case3){
	std::cout<< "**************t_shared_ptr_case3**************" <<std::endl;
	shared_ptr<std::string> sp = make_shared<std::string>("boost make shared");
	shared_ptr<std::vector<int> > spv = make_shared<std::vector<int> >(10, 2);
	BOOST_ASSERT(spv->size() == 10 && "spv size should be 10");
	std::cout<< "**************t_shared_ptr_case3**************" <<std::endl;
}

BOOST_AUTO_TEST_CASE(t_shared_ptr_case4){
	std::cout<< "**************t_shared_ptr_case4**************" <<std::endl;
	typedef std::vector<shared_ptr<int> > vs;
	vs v(10);
	int i = 0;
	for(vs::iterator it = v.begin(); it != v.end(); it++ ){
		(*it) = make_shared<int>(++i);
		std::cout << *(*it) << std::endl;
		BOOST_ASSERT(*(*it) == i);
	}

	shared_ptr<int> p = v[9];
	*p = 100;

	BOOST_ASSERT(*v[9] == 100 && "*v[9] should be 100");
	std::cout<< "**************t_shared_ptr_case4**************" <<std::endl;
}

BOOST_AUTO_TEST_SUITE_END()
