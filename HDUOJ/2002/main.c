#include <stdio.h>
#define PI 3.1415927

int main(void)
{
	double radius;
	
	while(scanf("%lf", &radius) != EOF)
	{
		printf("%.3f\n", ((double)4/(double)3)*radius*radius*radius*PI);
	}
	
	return 0;
}
