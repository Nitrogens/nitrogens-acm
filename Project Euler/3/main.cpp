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
		//��֤��iһ�������� 
		result = i;
		while(number % i == 0)	number /= i;
	}
	
	//��֤�����µ�numberһ�������� 
	if(number > result)	result = number;
	
	printf("%d\n", result);
	
	return 0;
}
