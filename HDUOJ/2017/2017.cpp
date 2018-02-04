#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int number[105];
int main(void)
{
	int n, i, j, count;
	char str[100000];
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		memset(str, '\0', sizeof(str));
		
		scanf("%s", str);
		
		count = 0;
		for(j=0; j<strlen(str); j++)
		{
			if(str[j]>='0' && str[j]<='9')
			{
				count++;
			}
		}
		printf("%d\n", count);
	}
	
	return 0;
}
