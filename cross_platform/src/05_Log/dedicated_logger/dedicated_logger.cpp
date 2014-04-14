#define BOOST_TEST_MAIN

#include <iostream>
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/move/utility.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

BOOST_AUTO_TEST_SUITE(dedicated_logger_log)
BOOST_AUTO_TEST_CASE(dedicated_logger)
{
	logging::add_file_log("dedicated_logger_object.log");
    logging::add_common_attributes();

	src::logger lg;

    logging::record rec = lg.open_record();
    if (rec)
    {
        logging::record_ostream strm(rec);
        strm << "Hello, World!";
        strm.flush();
        lg.push_record(boost::move(rec));
    }
	//BOOST_LOG(lg) << "Hello, World!";
}

BOOST_AUTO_TEST_SUITE_END()

