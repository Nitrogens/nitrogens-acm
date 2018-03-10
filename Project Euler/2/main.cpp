#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
int main(void)
{
	long long a1, a2, temp;
	long long sum = 0;
	
	a1 = 1;
	a2 = 2;
	
	while(a2 <= 4000000)
	{
		if(a2 % 2 == 0)
			sum += a2;
		temp = a2;
		a2 = a1+a2;
		a1 = temp;
	}
	
	printf("%d\n", sum);
	
	return 0;
}
