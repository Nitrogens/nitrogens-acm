#include <stdio.h>
int main(void)
{
	int a, b;
	
	while(scanf("%x %x", &a, &b) != EOF)
	{
		printf("%d\n", a+b);
	}
	
	return 0;
}
