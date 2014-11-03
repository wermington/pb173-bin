#include <stdarg.h>
#include <asm/unistd.h>

#ifdef __x86_64__
# define ASM_LINKAGE
#else
# define ASM_LINKAGE __attribute__((regparm(0)))
#endif

long ASM_LINKAGE syscall(unsigned int number, ...);

asm(
	"syscall:\n"
#ifdef __x86_64__
	"movq %rdi, %rax\n"
	"movq %rsi, %rdi\n"
	"movq %rdx, %rsi\n"
	"movq %rcx, %rdx\n"
	"movq %r8, %r10\n"
	"movq %r9, %r8\n"
	"movq 8(%rsp), %r9\n"
	"syscall\n"
#else
	"movl 4(%esp), %eax\n"
	"movl 8(%esp), %ebx\n"
	"movl 12(%esp), %ecx\n"
	"movl 16(%esp), %edx\n"
	"movl 20(%esp), %esi\n"
	"movl 24(%esp), %edi\n"
	"movl 28(%esp), %ebp\n"
	"int $0x80\n"
#endif
	"ret\n");

void start()
{
	char buf[16];
	syscall(__NR_read, 0, buf, 16);
}
