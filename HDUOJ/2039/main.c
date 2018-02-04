#include <stdio.h>
int main(void)
{
	int m, i;
	scanf("%d", &m);
	
	double a, b, c;
	
	for(i=0; i<m; i++)
	{
		scanf("%lf %lf %lf", &a, &b, &c);
		
		if((a + b > c)&&(a + c > b)&&(c + b > a))
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	
	return 0;
}
