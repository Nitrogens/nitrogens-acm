#include <stdio.h>
int main(void)
{
	int N, M, i, j, temp;
	int sum = 0;
	
	scanf("%d", &N);
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &M);
		
		for(j=0; j<M; j++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
		sum = 0;
	}
	
	return 0;
}
