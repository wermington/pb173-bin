#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	if (argc >= 2 && atoi(argv[1]) == 12345)
		puts("bingo");
	else
		puts("nothing");

	return 0;
}
