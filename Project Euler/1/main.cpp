#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
int main(void)
{
	int sum, i;
	sum = 0;
	
	for(i=3; i<1000; i+=3)
	{
		sum += i;
	}
	
	for(i=5; i<1000; i+=5)
	{
		sum += i;
	}
	
	for(i=15; i<1000; i+=15)
	{
		sum -= i;
	}
	
	printf("%d", sum);
	
	return 0;
}
