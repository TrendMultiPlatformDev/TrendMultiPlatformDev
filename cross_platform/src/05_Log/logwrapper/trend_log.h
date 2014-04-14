#ifndef __TREND_LOG_H__
#define __TREND_LOG_H__

//#pragma warning(disable:4819)
#include <boost/log/common.hpp>
#include <boost/log/support/date_time.hpp>
//#pragma warning(default:4819)
#define BOOST_LOG_DYN_LINK

// NOTE, please call trend::log::initializeLogger before call below macro (it is 
// better to call it at the begin of an application or dll)
#ifndef TM_DEBUG
#define TM_DEBUG(messageStream) TM_LOG_INTERNAL(DEBUG, messageStream)
#endif

#ifndef TM_INFO
#define TM_INFO(messageStream) TM_LOG_INTERNAL(INFO, messageStream)
#endif

#ifndef TM_WARN
#define TM_WARN(messageStream) TM_LOG_INTERNAL(WARN, messageStream)
#endif

#ifndef TM_ERROR
#define TM_ERROR(messageStream) TM_LOG_INTERNAL(ERROR, messageStream)
#endif

#ifndef TM_MSG
#define TM_MSG(messageStream) TM_LOG_INTERNAL(MSG, messageStream)
#endif

#ifndef TM_LOG_INTERNAL
#define TM_LOG_INTERNAL(level, messageStream) \
	BOOST_LOG_SEV(trend::log::logger::get(), trend::log::LL_##level) << #level << ' ' << messageStream;
#endif

namespace trend { namespace log {
	/**
    * User should call initializeLog before log(call TM_DEBUG, TM_INFO, 
    *   TM_WARN or TM_ERROR)
    */
    bool initializeLogger(const char* configFileName);

	enum log_severity_level {LL_DEBUG = 0, LL_INFO = 1, LL_WARN = 2, LL_ERROR = 3, LL_MSG = 9999 };
	BOOST_LOG_INLINE_GLOBAL_LOGGER_DEFAULT(logger, boost::log::sources::severity_logger_mt< >);
}}

#endif
