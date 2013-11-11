#include <stdarg.h>
#include <asm/unistd.h>

static __attribute((noinline,noclone)) long syscall(unsigned int number, ...)
{
	long ret;
#ifdef __x86_64__
	asm volatile(
		"movq %%rsi, %%rdi\n"
		"movq %%rdx, %%rsi\n"
		"movq %%rcx, %%rdx\n"
		"movq %%r8, %%r10\n"
		"movq %%r9, %%r8\n"
		"movq 8(%%rsp),%%r9\n"
		"syscall" : "=a" (ret) : "a" (number) : "r10", "rdi", "rsi", "rdx", "r8");
#else
	asm volatile(
		"movl 8(%%esp), %%ebx\n"
		"movl 12(%%esp), %%ecx\n"
		"movl 16(%%esp), %%edx\n"
		"movl 20(%%esp), %%esi\n"
		"movl 24(%%esp), %%edi\n"
		"movl 28(%%esp), %%ebp\n"
		"int $0x80" : "=a" (ret) : "a" (number) : "ebx", "ecx", "edx", "esi", "edi", "ebp");
#endif
	return ret;
}

void start()
{
	char buf[16];
	syscall(__NR_read, 0, buf, 16);
}
