#include "trend_log.h"
#include <fstream>
#include <boost/filesystem.hpp>
#include <boost/locale.hpp>

#pragma warning(disable:4819)
#include <boost/log/attributes.hpp>
#include <boost/log/utility/setup/from_stream.hpp>
#pragma warning(default:4819)

namespace trend { namespace log {
	bool initializeLogger(const char* configFileName) {
		std::locale loc = boost::locale::generator()("en_US.UTF-8");
		boost::filesystem::path::imbue(loc);

		try {
			std::ifstream settings(configFileName);
			boost::log::init_from_stream(settings);

			boost::shared_ptr< boost::log::core > core = boost::log::core::get();
			core->add_global_attribute("TimeStamp", boost::log::attributes::local_clock());
			core->add_global_attribute("ProcessID", boost::log::attributes::current_process_id());
			core->add_global_attribute("ThreadID", boost::log::attributes::current_thread_id());
		}
		catch (std::exception& e) {
			std::cerr << "Initialize logger failure: " << e.what() << std::endl;
			return false;
		}

		return true;
	}
}}
