#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int number[105];
bool reload(int a, int b);
int main(void)
{
	int n, i;
	scanf("%d", &n);
	
	while(n != 0)
	{
		memset(number, 0, sizeof(number));
		for(i=0; i<n; i++)
		{
			scanf("%d", &number[i]);
		}
		
		sort(number, number+n, reload);
		
		for(i=0; i<n; i++)
		{
			if(i==0)
				printf("%d", number[i]);
			else
				printf(" %d", number[i]);
		}
		printf("\n");
		scanf("%d", &n);
	}
	
	return 0;
}
bool reload(int a, int b)
{
	int tempa = a, tempb = b;
	if(tempa<0) tempa = -tempa;
	if(tempb<0) tempb = -tempb;
	
	return tempa>tempb;
}
