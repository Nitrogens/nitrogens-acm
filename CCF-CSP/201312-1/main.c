#include <stdio.h>
int main(void)
{
	int n, i, j, result, temp;
	scanf("%d", &n);
	
	int number[n], sum[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &number[i]);
		sum[i] = 1;
	}
	
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(i == j)
				continue;
				
			if(number[i] == number[j])
			{
				sum[i]++;
			}
		}
	}
	
	for(i=0; i<n; i++)
	{
		if(i == 0)
		{
			result = number[0];
			temp = sum[0];
		}
		else
		{
			if(sum[i] > temp)
			{
				temp = sum[i];
				result = number[i];
			}
			if(sum[i] == temp)
			{
				if(number[i] < result)
				{
					result = number[i];
				}
			}
		}
	}
	
	printf("%d", result);
	
	return 0;
}
