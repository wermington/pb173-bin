#include <err.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include <sys/socket.h>
#include <sys/types.h>

#include <linux/netlink.h>

static void server(int fd, const struct sockaddr_nl *saddr)
{
	/* TODO */
}

static void client(int fd, const struct sockaddr_nl *saddr, const char *msg)
{
	/* TODO */
}

int main(int argc, char **argv)
{
	struct sockaddr_nl saddr = {
		.nl_family = AF_NETLINK,
	};
	pid_t pid;
	int fd;

	fd = -1; /* TODO */

	if (argc == 3) {
		pid = atoi(argv[1]);
	} else if (argc == 1) {
		pid = getpid();
		if (pid < 0)
			err(1, "getpid");
		printf("listening with PID=%d\n", pid);
	} else
		errx(1, "bad args");

	saddr.nl_pid = pid;

	if (argc > 1)
		client(fd, &saddr, argv[2]);
	else
		server(fd, &saddr);

	close(fd);

	return 0;
}
