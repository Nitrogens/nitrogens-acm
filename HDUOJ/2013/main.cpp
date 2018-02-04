#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, i, result;
	
	while(scanf("%d", &n) != EOF)
	{
		result = 1;
		for(i=n-1; i>=1; i--)
		{
			result = (result+1)*2;
		}
		printf("%d\n", result);
	} 
	
	return 0;
}
