// Note, only one file can define BOOST_TEST_MODULE, which will define main and init function
//#define BOOST_TEST_MODULE test
#define BOOST_TEST_MAIN

#include "trend_log.h"
#include <boost/test/unit_test.hpp>

static void foo() {
	TM_DEBUG("debug log");
	TM_INFO("info log");
	TM_WARN("warn log");
	TM_ERROR("error log");
	TM_MSG("msg log");
}

BOOST_AUTO_TEST_SUITE(trend_logtest)
BOOST_AUTO_TEST_CASE( logtest ) {
	BOOST_ASSERT(trend::log::initializeLogger("boost-log.ini"));
	for (int i = 0; i < 1; ++i) {
		foo();
	}
}
BOOST_AUTO_TEST_SUITE_END()
