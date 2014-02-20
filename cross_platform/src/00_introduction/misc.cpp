#include "misc.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef __linux__
#include <unistd.h>
#include <cmath>
#endif

namespace trend {
	void sleep(unsigned int milliseconds) {
#ifdef _WIN32
		Sleep(milliseconds);
#elif __linux__
		::sleep(ceil(1.0*milliseconds/1000));
#else
		assert(false);
#endif
	}
}