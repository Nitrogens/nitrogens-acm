#include <stdio.h>
int main(void)
{
	int N, M;
	int i, j;
	int l, r, v;
	int opt;
	int opt2_num = 0;
	unsigned long long int result = 0;
	
	scanf("%d %d", &N, &M);
	
	int a[N];
	
	for(i=0; i<N; i++)
	{
		scanf("%d", &a[i]);
	}
	
	for(i=0; i<M; i++)
	{
		scanf("%d", &opt);
		
		switch (opt)
		{
			case 1:
				scanf("%d %d %d", &l, &r, &v);
				
				if((r-l) % 2 == 1)
				{
					for(j=l-1; j<=l-1+(r-l)/2; j++)
					{
						if(a[j] % v == 0)
						{
							a[j] /= v;
						}
						
						if(a[j+1+(r-l)/2] % v == 0)
						{
							a[j+1+(r-l)/2] /= v;
						}
					}
				}
				else
				{
					for(j=l-1; j<=r-1; j++)
					{
						if(a[j] % v == 0)
						{
							a[j] /= v;
						}
					}
				}
				
				break;
			case 2:
				scanf("%d %d", &l, &r);
				
				if((r-l) % 2 == 1)
				{
					for(j=l-1; j<=l-1+(r-l)/2; j++)
					{
						result += a[j] + a[j+1+(r-l)/2];
					}
				}
				else
				{
					for(j=l-1; j<=r-1; j++)
					{
						result += a[j];
					}
				}
				
				opt2_num++;
				
				if(opt2_num == 1)
				{
					printf("%llu", result);
				}
				else
				{
					printf("\n%llu", result);
				}
				
				result = 0;
				
				break;
		}
	}
	
	return 0;
}
