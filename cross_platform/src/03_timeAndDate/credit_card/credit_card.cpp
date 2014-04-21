#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

class credit_card{
public:
	std::string bank_name;               //������
	int bill_day_no;                     //������
	credit_card(const char* bname, int no):bank_name(bname), bill_day_no(no){}

	//������Ϣ�ڣ����ݴ���������յõ���һ�������գ��������Ϣ��
	int calc_free_days(date consume_day = day_clock::local_day()) const{
		date bill_day(consume_day.year(), consume_day.month(), bill_day_no);    //�õ�������

		if(consume_day > bill_day){                                             //�������Ƿ��Ѿ����˼�����
			bill_day += months(1);                                              //������������¸��µļ�����
		}

		return (bill_day - consume_day).days() + 20;                           //������Ϣ��
	}

	//Ϊ��֧�ֱȽ����㣬����С�ڱȽϲ�����
	friend bool operator<(const credit_card& l, const credit_card& r){
		//�Ƚ���Ϣ��
		return l.calc_free_days() < r.calc_free_days();
	}
};

BOOST_AUTO_TEST_CASE(d_credit1){
	credit_card a("A bank", 25);                              //A���м�������ÿ�µ�25��
	credit_card b("B bank", 12);                              //B���м�������ÿ�µ�12��

	credit_card tmp = std::max(a,b);
	std::cout << "You should use " << tmp.bank_name
		<< ", free days = " << tmp.calc_free_days() << std::endl;

}

//���������20��
BOOST_AUTO_TEST_CASE(d_credit2){
	credit_card a("A bank", 25);                              //A���м�������ÿ�µ�25��
	credit_card b("B bank", 12);                              //B���м�������ÿ�µ�12��

	date today(2014,3,20);                                    //������������
	int a_free_day = a.calc_free_days(today);                 //A����Ϣ��
	int b_free_day = b.calc_free_days(today);                 //B����Ϣ��
	credit_card tmp = (a_free_day<b_free_day)?b:a;            //�õ���Ϣ�ڴ���Ǹ�
	std::cout << "You should use " << tmp.bank_name
		<< ", free days = " << tmp.calc_free_days(today) << std::endl;

}