int div(int a, int b)
{
	return a / b;
}

int main(int argc, char **argv)
{
	return div(10, argc - 1) + argc;
}
