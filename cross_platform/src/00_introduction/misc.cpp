#include "misc.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#if defined __linux__ || defined __APPLE__
#include <assert.h>
#include <unistd.h>
#include <cmath>
#endif

namespace trend {
	void sleep(unsigned int milliseconds) {
#ifdef _WIN32
		Sleep(milliseconds);
#elif defined __linux__ || defined __APPLE__
		::sleep(ceil(1.0*milliseconds/1000));
#else
		assert(false);
#endif
	}
}