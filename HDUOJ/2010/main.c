#include <stdio.h>
int main(void)
{
	int m, n, i, a, b, c;
	int sum = 0;
	
	while(scanf("%d %d", &m, &n) != EOF)
	{
		for(i=m; i<=n; i++)
		{
			a = i / 100;
			b = i % 100 / 10;
			c = i % 10;
			
			if(i == a*a*a + b*b*b + c*c*c)
			{
				sum++;
				if(sum == 1)
				{
					printf("%d", i);
				}
				else
				{
					printf(" %d", i);
				}
			}
			
		}
		
		if(sum == 0)
		{
			printf("no");
		}
		
		sum = 0;
		
		printf("\n");
	}
	
	return 0;
}
