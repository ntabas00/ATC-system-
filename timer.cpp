#include "Timer.h"

Timer::Timer(uint32_t p_sec, uint32_t p_msec, uint32_t o_sec, uint32_t o_msec) {
	const int signal = SIGALARM;

	sigemptyset(&sig_set); // initialize a signal set
	sigaddset(&sig_set, signal); // add SIGALRM to the signal set
	sigprocmask(SIG_BLOCK, &sig_set, NULL); //block the signal

	/* set the signal event a timer expiration */
	memset(&sig_event, 0, sizeof(struct sigevent));
	sig_event.sigev_notify = SIGEV_SIGNAL;
	sig_event.sigev_signo = signal;

	// Check if timer was created succesfully
	if (timer_create(CLOCK_REALTIME, &sig_event, &timer_id) == -1) {
		std::cerr << "Timer, Init error : " << errno << "\n";
	}

	// Set the timer offset and period (both expressed in sec and nsec)
	set_timer(period_sec, 1000000 * period_msec, offset_sec, 1000000 * offset_msec);
	
}

Timer::~Timer() {
	
}

void Timer::setTimer(uint32_t p_sec, uint32_t p_nsec, uint32_t o_sec, uint32_t o_nsec) {
	timer_spec.it_value.tv_sec = o_sec;
	timer_spec.it_value.tv_nsec = o_nsec;
	timer_spec.it_interval.tv_sec = p_sec;
	timer_spec.it_interval.tv_nsec = p_nsec;
	// Start timer
	timer_settime(timer_id, 0, &timer_spec, NULL);
}

void Timer::wait_next_activation() {
	int dummy;
	/* suspend calling process until a signal is pending */
	sigwait(&sig_set, &dummy);
}