#include <stdio.h>
int main(void)
{
	int m, n, i, j;
	double temp;
	double sum = 0;
	
	scanf("%d", &m);
	
	for(i=0; i<m; i++)
	{
		scanf("%d", &n);
		
		for(j=1; j<=n; j++)
		{
			temp = (j%2==0)?(-(double)1/(double)j):((double)1/(double)j);
			sum += temp;
		}
		
		printf("%.2f\n", sum);
		
		sum = 0;
	}
	
	return 0;
}
