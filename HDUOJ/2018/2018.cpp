#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int number[55];
int main(void)
{
	int n, i;

	number[1] = 1;
	number[2] = 2;
	number[3] = 3;
	
	for(i=4; i<=54; i++)
	{
		number[i] = number[i-3] + number[i-1];
	}
	
	scanf("%d", &n);
	
	while(n != 0)
	{
		printf("%d\n", number[n]);
		scanf("%d", &n);
	}
	
	return 0;
}
