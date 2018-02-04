#include <stdio.h>
int main(void)
{
	int N, i, temp;
	scanf("%d", &N);
	
	int reader[N];
	
	for(i=0; i<N; i++)
	{
		reader[i] = 0;
	}
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &temp);
		reader[temp-1]++;
		if (i==N-1)
		{
			printf("%d", reader[temp-1]);
		}
		else
		{
			printf("%d ", reader[temp-1]);
		}
	}
	
	return 0;
}
