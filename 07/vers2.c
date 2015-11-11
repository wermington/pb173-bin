#include <stdio.h>

void bubak_ver1(void)
{
	puts("O1 COMPAT");
}
asm(".symver bubak_ver1,bubak@");

void bubak_ver2(void)
{
	puts("O2");
}
asm(".symver bubak_ver2,bubak@@VERS_1.1");
