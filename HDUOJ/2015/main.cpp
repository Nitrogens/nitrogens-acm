#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, m, sum, i;
	while(scanf("%d %d", &n, &m) != EOF)
	{
		if(n % m != 0)
			for(i=1; i<=(n/m+1); i++)
			{
				if(i==1)
				{
					printf("%d", m+1);
				}
				else if(i<(n/m+1))
				{
					printf(" %d", (2*i-1)*m+1);
				}
				else
				{
					printf(" %d", (i-1)*m+1+n);
				}
			}
		else
			for(i=1; i<=(n/m); i++)
			{
				if(i==1)
				{
					printf("%d", m+1);
				}
				else
				{
					printf(" %d", (2*i-1)*m+1);
				}
			}
		printf("\n");
	}
	
	return 0;
}
