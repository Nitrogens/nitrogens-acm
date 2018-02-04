#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int abs(int a);
int main(void)
{
	int m, n, i, j, max, temp, resultx, resulty;
	while(scanf("%d %d", &m, &n) != EOF)
	{
		max = 0;
		for(i=1; i<=m; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &temp);
				if(abs(temp)>abs(max))
				{
					resultx = i;
					resulty = j;
					max = temp;
				}
			}
		}
		
		printf("%d %d %d\n", resultx, resulty, max);
	}
	
	return 0;
}

int abs(int a)
{
	return (a<0)?(-a):a;
}
