#define BOOST_TEST_MAIN
#include <iostream>
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/move/utility.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sources/global_logger_storage.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

using namespace boost;
namespace logging = boost::log;
namespace src = boost::log::sources;
namespace keywords = boost::log::keywords;

BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(my_logger, src::logger_mt)
BOOST_AUTO_TEST_SUITE(global_logger_log)
BOOST_AUTO_TEST_CASE(global_logger)
{
	logging::add_file_log("global_logger_object.log");
    logging::add_common_attributes();

    src::logger_mt& lg = my_logger::get();
    BOOST_LOG(lg) << "Hello, World!";
}
BOOST_AUTO_TEST_SUITE_END()
