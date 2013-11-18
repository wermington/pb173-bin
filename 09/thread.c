#include <err.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static int my_pthread_create(pthread_t *thread, const pthread_attr_t *attr,
		void *(*start_routine) (void *), void *arg)
{
	int ret = pthread_create(thread, attr, start_routine, arg);
	if (!ret)
		return 0;

	errno = ret;
	return -1;
}

static void *thread(void *parm)
{
	while (1) {
		puts(parm);
		sleep(1);
	}

	return NULL;
}

int main(int argc, char **argv)
{
	pthread_t t1, t2;
	int ret;

	ret = my_pthread_create(&t1, NULL, thread, "a");
	if (ret)
		err(EXIT_FAILURE, "pthread_create(t1)");

	ret = my_pthread_create(&t2, NULL, thread, "b");
	if (ret)
		err(EXIT_FAILURE, "pthread_create(t2)");

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	return 0;
}
