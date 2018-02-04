#include <stdio.h>
int main(void)
{
	int n, k, i;
	int sum = 0;
	int temp = 0;
	
	scanf("%d %d", &n, &k);
	
	int cake[n];
	
	for (i=0; i<n; i++)
	{
		scanf("%d", &cake[i]);
	}
	
	for (i=0; i<n; i++)
	{
		temp += cake[i];
		if(temp >= k)
		{
			temp = 0;
			sum++;
		}
		if( (i == n-1) && (temp != 0) )
			sum++;
	}
	
	printf("%d", sum);
	
	return 0;
}
