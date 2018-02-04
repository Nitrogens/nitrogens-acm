#include <stdio.h>
#include <math.h>
int main(void)
{
	int a, b, c, k, result;
	char d;
	scanf("%d-%d-%d-%c", &a, &b, &c, &d);
	
	int digit_b = 0, digit_c = 0;
	int temp;
	
	temp = b;
	
	if(temp == 0)
		digit_b = 1;
	
	while(temp > 0)
	{
		temp /= 10;
		digit_b++;
	}
	
	temp = c;
	
	if(temp == 0)
		digit_c = 1;
	
	while(temp > 0)
	{
		temp /= 10;
		digit_c++;
	}
	
	int digit_container_b[3];
	int digit_container_c[5];
	
	temp = b;
	
	for(k=0; k<=2; k++)
	{
		if(k>=3-digit_b)
		{
			digit_container_b[k] = temp / (int)pow(10, 2-k);
			temp -= digit_container_b[k] * (int)pow(10, 2-k);
		}
		else
		{
			digit_container_b[k] = 0;
		}
	}
	
	temp = c;
	
	for(k=0; k<=4; k++)
	{
		if(k>=5-digit_c)
		{
			digit_container_c[k] = temp / (int)pow(10, 4-k);
			temp -= digit_container_c[k] * (int)pow(10, 4-k);
		}
		else
		{
			digit_container_c[k] = 0;
		}
	}
	
	result = a*1 + digit_container_b[0]*2 + digit_container_b[1]*3 + digit_container_b[2]*4 + digit_container_c[0] * 5 + digit_container_c[1] * 6
			+ digit_container_c[2] * 7 + digit_container_c[3] * 8 + digit_container_c[4] * 9;
	result %= 11;
	
	d = (d=='X')?10:(d-48);	//ASCII-48对应的字符是'0' 
	
	if(result == d)
	{
		printf("Right");
	}
	else
	{
		if(result == 10)
		{
			printf("%d-%03d-%05d-X", a, b, c);
		}
		else
		{
			printf("%d-%03d-%05d-%d", a, b, c, result);
		}
	}
	
	return 0;
}
