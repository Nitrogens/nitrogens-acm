#include <stdio.h>
int main(void)
{
	int n, i;
	int sum = 0;
	scanf("%d", &n);
	
	int number[n], status[n-1];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &number[i]);
	}
	
	for(i=0; i<n-1; i++)
	{
		status[i] = (number[i+1]>number[i])?1:0;
		if (i!=0)
		{
			if (status[i] != status[i-1])
			{
				sum++;
			}
		}
	}
	
	printf("%d", sum);
	
	return 0;
}
