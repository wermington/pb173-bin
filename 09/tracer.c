#include <stdio.h>

int main(void)
{
	fwrite("a", 1, 1, stdout);
	fwrite("b", 1, 1, stdout);
	fwrite("\n", 1, 1, stdout);

	return 0;
}
