
#include <cstdio>

class Test
{
	public:
	Test()
{
	printf("before main\n");
	int * p= NULL;
	*p = 1;
}

};

Test t;

int main()
{
	printf("program started\n");
	return 0;
}