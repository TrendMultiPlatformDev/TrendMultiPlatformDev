#include "singleton.h"

#include <string>

#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/thread/mutex.hpp>

using namespace std;
using namespace boost::posix_time;
using namespace trend;

SomeLogdPtr SomeLogd::s_pLogdInstance = NULL;

SomeLogdPtr SomeLogd::GetInstance()
{
	if(s_pLogdInstance == NULL)
		s_pLogdInstance.reset(new SomeLogd());

	return s_pLogdInstance;
}

void SomeLogd::ResetInstance()
{
	s_pLogdInstance.reset();
}

void SomeLogd::Log(const char *str)
{
	boost::mutex::scoped_lock lock(m_mtxLog);

	ptime now = second_clock::local_time();  
	string strDateTime = to_iso_extended_string(now.date()) + 
		" " + to_simple_string(now.time_of_day()) + ": ";  

	m_strLogBuffer.append(strDateTime);
	m_strLogBuffer.append(str);
	m_strLogBuffer.append("\n");
}

std::string SomeLogd::GetLog()
{ 
	boost::mutex::scoped_lock lock(m_mtxLog);
	return m_strLogBuffer; 
}
