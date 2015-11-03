int main()
{
#if LIB_VER < 3
	extern void bubak(void);
	bubak();
#else
	extern void bubak(int);
	bubak(50);
#endif
	return 0;
}
