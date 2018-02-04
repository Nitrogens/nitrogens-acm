#include <stdio.h>
int main(void)
{
	int n, i, j;
	int small = 0, big = 0, result = -1;;
	scanf("%d", &n);
	
	int number[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &number[i]);
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i == j)
				continue;
				
			if(number[i] < number[j])
			{
				big++;
			}
			if(number[i] > number[j])
			{
				small++;
			}
		}
		
		if(big == small)
		{
			result = number[i];
		}
		
		big = 0;
		small = 0;
	}
	
	printf("%d", result);
	
	return 0;
}
