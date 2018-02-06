#include <cstdio>
#include <cstring>
#include <cstdlib>
double polish();
int main(void)
{
	printf("%f\n", polish());
	
	return 0;
}

double polish()
{
	char str[100];
	scanf("%s", str);
	
	switch(str[0])
	{
		case '+':
			return polish() + polish();
			break;
		case '-':
			return polish() - polish();
			break;
		case '*':
			return polish() * polish();
			break;
		case '/':
			return polish() / polish();
			break;
		default:
			return atof(str);
			break;
	}
}
