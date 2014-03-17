#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <string>

#include <boost/noncopyable.hpp>
#include <boost/serialization/singleton.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/utility.hpp>

namespace trend
{
	class SomeLogd;

	class SomeLogd: public boost::serialization::singleton<SomeLogd>
	{
	private:
		boost::mutex m_mtxLog;
		std::string m_strLogBuffer;

	public:
		void Log(const char *str);
		std::string GetLog();
		
	};

}

#endif
