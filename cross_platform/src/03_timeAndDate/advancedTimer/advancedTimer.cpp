#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
using namespace boost::posix_time;

template<typename Clock = microsec_clock>           //ȱʡʹ��microsec_clock
class basic_ptimer{
public:
	basic_ptimer(){                                 //���캯��,��ʼ����ʼʱ��
		restart();
	}
	void restart(){                                 //���¿�ʼ��ʱ
		_start_time = Clock::local_time();
	}
	void elapsed() const{                           //�������ŵ�ʱ��
		std::cout << Clock::local_time() - _start_time;
	}
	~basic_ptimer(){                                //����ʱ�Զ����ʱ��
		elapsed();
	}

private:
	ptime _start_time;                              //˽�б����������ʱ��ʼʱ��
};

typedef basic_ptimer<microsec_clock> ptimer;        //typedef������
typedef basic_ptimer<second_clock> sptimer;

BOOST_AUTO_TEST_CASE(d_timer1){
	ptimer t;
	for(int i = 0; i < 10;i++){
		std::cout << i << std::endl;
	}
}