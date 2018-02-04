#include <stdio.h>
int main(void)
{
	int N, i;
	scanf("%d", &N);
	
	int a[N], b[N];
	
	for(i=0; i<N; i++)
	{
		scanf("%d %d", &a[i], &b[i]);
	}
	
	for(i=0; i<N; i++)
	{
		printf("%d\n", a[i]+b[i]);
	}
	
	return 0;
}
