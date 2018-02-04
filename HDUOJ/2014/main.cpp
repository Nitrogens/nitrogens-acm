#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int mark[100];
int main(void)
{
	int n, i;
	double result;
	
	while(scanf("%d", &n) != EOF)
	{
		memset(mark, 0, sizeof(mark));
		result = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &mark[i]);
		}
		
		sort(mark, mark+n);
		
		for(i=1; i<n-1; i++)
		{
			result += mark[i];
		}
		
		result /= (n-2);
		
		printf("%.2lf\n", result);
	}
	
	return 0;
}
