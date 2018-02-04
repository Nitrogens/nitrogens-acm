#include <stdio.h>
#include <math.h>
int main(void)
{
	int m, n, i;
	double sum = 0;
	double temp;
	
	while(scanf("%d %d", &n, &m) != EOF)
	{
		for(i=0; i<m; i++)
		{
			if(i == 0)
			{
				sum += n;
				temp = sqrt(n);
			}
			else
			{
				sum += temp;
				temp = sqrt(temp);
			}
		}
		
		printf("%.2f\n", sum);
		
		sum = 0;
	}
	
	return 0;
}
