#define BOOST_TEST_MAIN

#include <iostream>
#include <boost/log/trivial.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/assert.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/sinks/text_file_backend.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/utility/setup/console.hpp>
#include <boost/move/utility.hpp>
#include <boost/log/sources/logger.hpp>
#include <boost/log/sources/global_logger_storage.hpp>


#include <cstddef>
#include <string>
#include <ostream>
#include <fstream>
#include <iomanip>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared_object.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/log/core.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/attributes.hpp>
#include <boost/log/attributes/clock.hpp>
#include <boost/log/sources/basic_logger.hpp>
#include <boost/log/sources/severity_logger.hpp>
#include <boost/log/sources/record_ostream.hpp>
#include <boost/log/sinks/sync_frontend.hpp>
#include <boost/log/sinks/text_ostream_backend.hpp>
#include <boost/log/attributes/scoped_attribute.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

using namespace boost;


BOOST_AUTO_TEST_SUITE(boost_log)
BOOST_AUTO_TEST_CASE(trivial)
{
	std::cout<<"start test trivial\n";
	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
}

BOOST_AUTO_TEST_CASE(trivial_filter)
{
	std::cout<<"\n\nstart test trivial_filter\n";
	namespace logging = boost::log;
	logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );

	BOOST_LOG_TRIVIAL(trace) << "A trace severity message";
    BOOST_LOG_TRIVIAL(debug) << "A debug severity message";
    BOOST_LOG_TRIVIAL(info) << "An informational severity message";
    BOOST_LOG_TRIVIAL(warning) << "A warning severity message";
    BOOST_LOG_TRIVIAL(error) << "An error severity message";
    BOOST_LOG_TRIVIAL(fatal) << "A fatal severity message";
}

BOOST_AUTO_TEST_CASE(trivial_to_file_1)
{
	std::cout<<"\n\nstart test trivial_to_file_1\n";
	namespace logging = boost::log;
	namespace src = boost::log::sources;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	
	logging::add_file_log("logging_to_file_01.log");
	logging::add_console_log(std::cout);

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );


	logging::add_common_attributes(); 

    using namespace logging::trivial;
    src::severity_logger< severity_level > lg;

    BOOST_LOG_SEV(lg, trace) << "A trace severity message";
    BOOST_LOG_SEV(lg, debug) << "A debug severity message";
    BOOST_LOG_SEV(lg, info) << "An informational severity message";
    BOOST_LOG_SEV(lg, warning) << "A warning severity message";
    BOOST_LOG_SEV(lg, error) << "An error severity message";
    BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";
}

BOOST_AUTO_TEST_CASE(trivial_to_file_2)
{
	std::cout<<"\n\nstart test trivial_to_file_2\n";
	namespace logging = boost::log;
	namespace src = boost::log::sources;
	namespace sinks = boost::log::sinks;
	namespace keywords = boost::log::keywords;
	
	logging::add_file_log
    (
        keywords::file_name = "logging_to_file_02_%N.log",                    /*< file name pattern >*/
        keywords::rotation_size = 2 * 1024,                                   /*< rotate files every 2 MiB... >*/
        keywords::time_based_rotation = sinks::file::rotation_at_time_point(0, 0, 0), /*< ...or at midnight >*/
        keywords::format = "[%TimeStamp%]: %Message%"                                 /*< log record format >*/
    );

    logging::core::get()->set_filter
    (
        logging::trivial::severity >= logging::trivial::info
    );

	logging::add_common_attributes();

    using namespace logging::trivial;
    src::severity_logger< severity_level > lg;

	for(int i=0;i<20;++i)
	{
		BOOST_LOG_SEV(lg, trace) << "A trace severity message";
		BOOST_LOG_SEV(lg, debug) << "A debug severity message";
		BOOST_LOG_SEV(lg, info) << "An informational severity message";
		BOOST_LOG_SEV(lg, warning) << "A warning severity message";
		BOOST_LOG_SEV(lg, error) << "An error severity message";
		BOOST_LOG_SEV(lg, fatal) << "A fatal severity message";
	}
	
}


BOOST_AUTO_TEST_SUITE_END()