#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

class credit_card{
public:
	std::string bank_name;               //银行名
	int bill_day_no;                     //记账日
	credit_card(const char* bname, int no):bank_name(bname), bill_day_no(no){}

	//计算免息期，依据传入的消费日得到下一个记账日，并算出免息期
	int calc_free_days(date consume_day = day_clock::local_day()) const{
		date bill_day(consume_day.year(), consume_day.month(), bill_day_no);    //得到记账日

		if(consume_day > bill_day){                                             //消费日是否已经过了记账日
			bill_day += months(1);                                              //如果过了则是下个月的记账日
		}

		return (bill_day - consume_day).days() + 20;                           //计算免息期
	}

	//为了支持比较运算，重载小于比较操作符
	friend bool operator<(const credit_card& l, const credit_card& r){
		//比较免息期
		return l.calc_free_days() < r.calc_free_days();
	}
};

BOOST_AUTO_TEST_CASE(d_credit1){
	credit_card a("A bank", 25);                              //A银行记账日是每月的25号
	credit_card b("B bank", 12);                              //B银行记账日是每月的12号

	credit_card tmp = std::max(a,b);
	std::cout << "You should use " << tmp.bank_name
		<< ", free days = " << tmp.calc_free_days() << std::endl;

}

//假设今天是20号
BOOST_AUTO_TEST_CASE(d_credit2){
	credit_card a("A bank", 25);                              //A银行记账日是每月的25号
	credit_card b("B bank", 12);                              //B银行记账日是每月的12号

	date today(2014,3,20);                                    //构造今天的日期
	int a_free_day = a.calc_free_days(today);                 //A的免息期
	int b_free_day = b.calc_free_days(today);                 //B的免息期
	credit_card tmp = (a_free_day<b_free_day)?b:a;            //得到免息期大的那个
	std::cout << "You should use " << tmp.bank_name
		<< ", free days = " << tmp.calc_free_days(today) << std::endl;

}