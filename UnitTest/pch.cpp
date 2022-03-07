//
// pch.cpp
//

#include "pch.h"
#include <chrono>
#include <thread>

void Delay1Sec(void) {
	using namespace std::this_thread;
	using namespace std::chrono;
	sleep_for(nanoseconds(10));
	sleep_until(system_clock::now() + seconds(1));
}