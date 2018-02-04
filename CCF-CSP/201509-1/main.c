#include <stdio.h>
int main(void)
{
	int n, i, temp;
	int sum = 1;
	scanf("%d", &n);
	
	int number[n];
	
	for(i=0; i<n; i++)
	{
		scanf("%d", &number[i]);
	}
	
	for(i=0; i<n; i++)
	{
		if (i==0)
		{
			temp = number[i];
		}
		else
		{
			if (number[i] != temp)
			{
				sum++;
				temp = number[i];
			}
		}
	}
	
	printf("%d", sum);
	
	return 0;
}
