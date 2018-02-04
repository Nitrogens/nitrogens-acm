#include <stdio.h>

int main(void)
{
	int N, M, i, j, k, id, length;
	scanf("%d", &N);
	
	int position[N];
	
	for(i=0; i<N; i++)
	{
		position[i] = i + 1;
	}
	
	scanf("%d", &M);
	
	for(i=0; i<M; i++)
	{
		scanf("%d %d", &id, &length);
		id--;
		
		if(length > 0)
		{
			for(j=position[id]+1; j<=position[id]+length; j++)
			{
				for(k=0; k<N; k++)
				{
					if(position[k] == j)
					{
						position[k]--;
					}
				}
			}
		}
		
		if(length < 0)
		{
			for(j=position[id]-1; j>=position[id]+length; j--)
			{
				for(k=0; k<N; k++)
				{
					if(position[k] == j)
					{
						position[k]++;
					}
				}
			}
		}
		
		position[id] += length;
	}
	
	for(i=1; i<=N; i++)
	{
		for(j=0; j<N; j++)
		{
			if( position[j] == i )
			{
				if(i > 1)
				{
					printf(" %d", j+1);
				}
				else
				{
					printf("%d", j+1);
				}
			}
		}
	}
	
	return 0;
}
