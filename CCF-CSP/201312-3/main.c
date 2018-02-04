#include <stdio.h>

int main(void)
{
	int N, i, j, result;
	int sum = 0;
	scanf("%d", &N);
	
	int height[N];
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &height[i]);
	}
	
	for(i=0; i<N; i++)
	{
		for(j=i-1; j>=0; j--)
		{
			if(height[j] < height[i])
			{
				break;
			}
			else
			{
				sum += height[i];
			}
			
		}
		
		for(j=i+1; j<N; j++)
		{
			if(height[j] < height[i])
			{
				break;
			}
			else
			{
				sum += height[i];
			}
			
		}
		
		sum += height[i];
		
		if(i == 0)
		{
			result = sum;
		}
		else
		{
			if(sum > result)
			{
				result = sum;
			}
		}
		
		sum = 0;
	}
	
	printf("%d", result);
	
	return 0;
}
