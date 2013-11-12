#include <stdio.h>


static __attribute__((noinline)) void fun3(void)
{
	unsigned int a;

	for (a = 0; a < 300000; a++)
		asm volatile("nop" ::: "memory");
}

static __attribute__((noinline)) void fun2(void)
{
	unsigned int a;

	for (a = 0; a < 100000; a++)
		asm volatile("nop" ::: "memory");
}

static __attribute__((noinline)) void fun1(void)
{
	unsigned int a;

	for (a = 0; a < 500; a++)
		fun2();

	for (a = 0; a < 1000; a++)
		fun3();
}

int main(void)
{
	fun1();

	return 0;
}
