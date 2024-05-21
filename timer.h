#ifndef TIMER_H_
#define TIMER_H_

#include <stdio.h>
#include <iostream>
#include <time.h>

#include <sync.h>
#include <sys/siginfo.h>
#include <sys/neutrino.h>
#include <sys/netmgr.h>
#include <sys/syspage.h>
#include <inttypes.h>
#include <stdint.h>

class Timer {
	timer_t timer_id;
	struct sigevent sig_event;
	sigset_t sig_set;
	struct itimerspec timer_spec;
	struct timespec tv;
public:
	Timer(uint32_t p_sec, uint32_t p_msec, uint32_t o_sec, uint32_t o_msec);
	~Timer();
	void setTimer(uint32_t p_sec, uint32_t p_nsec, uint32_t o_sec, uint32_t o_nsec);
	void wait_next_activation();
};

#endif 