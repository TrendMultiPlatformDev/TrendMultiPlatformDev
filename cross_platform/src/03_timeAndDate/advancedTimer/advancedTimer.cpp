#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;

template<typename Clock = microsec_clock>           //缺省使用microsec_clock
class basic_ptimer{
public:
	basic_ptimer(){                                 //构造函数,初始化起始时间
		restart();
	}
	void restart(){                                 //重新开始计时
		_start_time = Clock::local_time();
	}
	void elapsed() const{                           //度量流逝的时间
		std::cout << Clock::local_time() - _start_time;
	}
	~basic_ptimer(){                                //析构时自动输出时间
		elapsed();
	}

private:
	ptime _start_time;                              //私有变量，保存计时开始时间
};

typedef basic_ptimer<microsec_clock> ptimer;        //typedef具体类
typedef basic_ptimer<second_clock> sptimer;

BOOST_AUTO_TEST_CASE(d_timer1){
	ptimer t;
	for(int i = 0; i < 10;i++){
		std::cout << i << std::endl;
	}
}