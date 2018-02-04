#include <cstdio>
#include <cstring>
using namespace std;
bool is_prime[5000];
void prime_fliter(int range);
int main(void)
{
	int x, y, i, flag;
	memset(is_prime, true, sizeof(is_prime));
	prime_fliter(5000);
	
	while(scanf("%d %d", &x, &y) != EOF)
	{
		if(x==0 && y==0)
			break;
		flag = 0;
		for(i=x; i<=y; i++)
		{
			if(!is_prime[i*i+i+41])
			{
				flag = 1;
				break;
			}
		}
		if(flag == 0)
		{
			printf("OK\n");
		}
		else
		{
			printf("Sorry\n");
		}
	}
	
	
	return 0;
}
void prime_fliter(int range)
{
	int i, j;
	is_prime[1] = false;
	
	for(i=2; i<=range; i++)
	{
		for(j=i*i; j<=range; j*=i)
		{
			is_prime[j] = false;
		}
	}
} 
