#include <stdio.h>
int sum(int n);
int main(void)
{
	int n;

	while(scanf("%d", &n) != EOF)
	{
		printf("%d\n\n", sum(n));
	}
	
	return 0;
}
int sum(int n)
{
	int result = 0;
	int i;
	
	if(n > 0)
	{
		for(i=1; i<=n; i++)
		{
			result += i;
		}
	}
	else
	{
		for(i=-1; i>=n; i--)
		{
			result += i;
		}
	}
	
	return result;
}
