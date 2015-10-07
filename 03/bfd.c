#include <bfd.h>
#include <stdio.h>
#include <stdlib.h>

static void print_targets(void)
{
	/* bfd_target_list() */
}

static void print_archs(void)
{
	/* bfd_arch_list() */
}

int main(void)
{
	bfd_init();

	print_targets();

	puts("\n===\n");

	print_archs();

	return 0;
}
