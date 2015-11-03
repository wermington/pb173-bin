#include <err.h>
#include <stdint.h>
#include <stdio.h>
#include <time.h>

#include <sys/io.h>

static void usleep(unsigned long us)
{
	struct timespec t = {
		.tv_nsec = us * 1000,
	};
	nanosleep(&t, NULL);
}

static void msleep(unsigned long ms)
{
	usleep(ms * 1000);
}

static void beep(unsigned int hz)
{
	uint16_t div = 0x1234dd / hz;

	(void)div;
}

static void stop_beep(void)
{
}

static void play(void)
{
	beep(1000);
	msleep(500);
	beep(1500);
	msleep(500);
	beep(1800);
	msleep(500);
	beep(300);
	msleep(500);
	stop_beep();
}

int main(void)
{
	play();

	return 0;
}
