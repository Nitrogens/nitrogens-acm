#include <stdio.h>
int main(void)
{
	int N, i, j;
	int sum = 0;
	scanf("%d", &N);
	
	int number[N];
	for (i=0; i<N; i++)
	{
		scanf("%d", &number[i]);
	}
	
	for(i=0; i<N-1; i++)
	{
		for(j=i+1; j<N; j++)
		{
			if( (number[i] - number[j] == 1) || (number[i] - number[j] == -1) )
				sum++;
		}
	}
	
	printf("%d", sum);
	return 0;
}
