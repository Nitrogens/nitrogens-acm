#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int number[105];
int main(void)
{
	int n, i, count;
	scanf("%d", &n);
	
	while(n != 0)
	{
		memset(number, 0, sizeof(number));
		for(i=0; i<n; i++)
		{
			scanf("%d", &number[i]);
		}
		count = 0;
		for(i=0; i<n; i++)
		{
			count += number[i]/100;
			number[i] %= 100;
			count += number[i]/50;
			number[i] %= 50;
			count += number[i]/10;
			number[i] %= 10;
			count += number[i]/5;
			number[i] %= 5;
			count += number[i]/2;
			number[i] %= 2;
			count += number[i];
		}
		printf("%d\n", count);
		scanf("%d", &n);
	}
	
	return 0;
}
