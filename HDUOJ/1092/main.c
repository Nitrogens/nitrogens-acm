#include <stdio.h>
int main(void)
{
	int N, i, temp;
	int sum = 0;
	
	scanf("%d", &N);
	
	while(N != 0)
	{
		for(i=0; i<N; i++)
		{
			scanf("%d", &temp);
			sum += temp;
		}
		printf("%d\n", sum);
		
		sum = 0;
		
		scanf("%d", &N);
	}
	
	return 0;
}
