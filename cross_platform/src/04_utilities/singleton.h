#ifndef _SINGLETON_H_
#define _SINGLETON_H_

#include <string>

#include <boost/thread/mutex.hpp>
#include <boost/noncopyable.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/utility.hpp>

namespace trend
{
	class SomeLogd;

	typedef boost::shared_ptr<SomeLogd> SomeLogdPtr;

	class SomeLogd: public boost::noncopyable
	{
	private:
		SomeLogd() {}

		boost::mutex m_mtxLog;
		
		std::string m_strLogBuffer;

		static SomeLogdPtr s_pLogdInstance;

	public:
		void Log(const char *str);

		std::string GetLog();

		static SomeLogdPtr GetInstance();
		static void ResetInstance();
		
	};

}

#endif
