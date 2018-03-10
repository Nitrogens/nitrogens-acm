#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
int main(void)
{
	long long number = 600851475143;
	long long i, result;
	
	for(i=2; i*i<number; i++)
	{
		if(number % i)	continue;
		//可证明i一定是素数 
		result = i;
		while(number % i == 0)	number /= i;
	}
	
	//可证明余下的number一定是素数 
	if(number > result)	result = number;
	
	printf("%d\n", result);
	
	return 0;
}
