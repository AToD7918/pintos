#ifndef DEVICES_TIMER_H
#define DEVICES_TIMER_H

#include <round.h>
#include <stdint.h>

/* Number of timer interrupts per second. */
#define TIMER_FREQ 100

void timer_init (void);
void timer_calibrate (void);

int64_t timer_ticks (void);
// already in   timer.c -> line 71
/* Returns the number of timer ticks since the OS booted. */

int64_t timer_elapsed (int64_t);
// already in   timer.c -> line 82
/* Returns the number of timer ticks elapsed since THEN, which
   should be a value once returned by timer_ticks(). */
//      return timer_ticks() - then;

/* Sleep and yield the CPU to other threads. */
void timer_sleep (int64_t ticks);
// already in   timer.c -> line 90

void timer_msleep (int64_t milliseconds);
void timer_usleep (int64_t microseconds);
void timer_nsleep (int64_t nanoseconds);

/* Busy waits. */
void timer_mdelay (int64_t milliseconds);
void timer_udelay (int64_t microseconds);
void timer_ndelay (int64_t nanoseconds);

void timer_print_stats (void);

#endif /* devices/timer.h */
