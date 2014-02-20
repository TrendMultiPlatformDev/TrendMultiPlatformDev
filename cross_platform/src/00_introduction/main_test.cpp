// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
#define BOOST_TEST_MODULE test

#include "misc.h"
#include <ctime>
#include <boost/test/unit_test.hpp>
#include <boost/thread.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

BOOST_AUTO_TEST_CASE( sleep_test ) {
	time_t tm = time(NULL);
	trend::sleep(2000);
	BOOST_ASSERT(time(NULL) - tm > 1);
}

BOOST_AUTO_TEST_CASE( boost_sleep_test ) {
	time_t tm = time(NULL);
	boost::this_thread::sleep(boost::posix_time::milliseconds(2000));
	BOOST_ASSERT(time(NULL) - tm > 1);
}

