#include <stdio.h>

void xy_ver1(void)
{
	puts("O1 COMPAT");
}
asm(".symver xy_ver1,bubak@");

void xy_ver2(void)
{
	puts("O2");
}
asm(".symver xy_ver2,bubak@VERS_1.1");

void xy_ver3(int x)
{
	printf("N%d\n", x);
}
asm(".symver xy_ver3,bubak@@VERS_2.0");
