#include <stdio.h>
int main(void)
{
	int T, N, i, j, k, temp;
	int	a[100000];
	
	scanf("%d", &T);
	
	for(i=1; i<=T; i++)
	{
		scanf("%d", &N);
		
		for(j=0; j<N; j++)
		{
			scanf("%d", &a[j]);
		}
		
		for(j=0; j<N-1; j++)
		{
			for(k=j+1; k<N; k++)
			{
				if(a[k-1] > a[k])
				{
					if(a[k-1] > 0)
					{
						temp = a[k-1];
						a[k] = a[k-1];
						a[k-1] = temp;
					}
					else
					{
						start = N-j;
						end
						j=N-1;
						break;
					}
				}
			}
		}
	}
	
	return 0;
}
