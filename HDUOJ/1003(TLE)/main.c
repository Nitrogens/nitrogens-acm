#include <stdio.h>
int main(void)
{
	int T, N, i, j, k, l, result, temp, start, end;
	scanf("%d", &T);
	
	int a[100000];
	
	for(i=0; i<T; i++)
	{
		scanf("%d", &N);
		
		for(j=0; j<N; j++)
		{
			scanf("%d", &a[j]);
		}
		
		for(j=N; j>=1; j--)
		{
			if(j == N)
			{
				result = 0;
				for(k=0; k<N; k++)
				{
					result += a[k];
				}
				start = 1;
				end = N;
			}
			else
			{
				
				for(l=0; l<=N-j; l++)
				{
					temp = 0;
					
					for(k=l; k<j+l; k++)
					{
						temp += a[k];
					}
					
					if(temp > result)
					{
						result = temp;
						start = l+1;
						end = l+j;
					}
				}
				
			}
		}
		
		printf("Case %d:\n%d %d %d\n", i+1, result, start, end);
	}
	
	return 0;
}
