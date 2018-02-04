#include <stdio.h>
int main(void)
{
	int n, i;
	int a = 0;
	int b = 0;
	int c = 0;
	double temp;
	
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
		{
			break;
		}
		
		for(i=0; i<n; i++)
		{
			scanf("%lf", &temp);
			
			if(temp < 0)
			{
				a++;
			}
			
			if(temp == 0)
			{
				b++;
			}
			
			if(temp > 0)
			{
				c++;
			}
		}
		
		printf("%d %d %d\n", a, b, c);
		
		a = 0;
		b = 0;
		c = 0;
	}
	
	return 0;
}
