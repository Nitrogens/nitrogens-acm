#include <cstdio>
#include <cstring>

using namespace std;
int n;
int place[300];
bool isfinish;
int abs(int a);
void solve(int start_column);
int main(void)
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		
		isfinish = false;	
		solve(0);
	}
	
	return 0;
}

int abs(int a)
{
	return (a < 0)?(-a):a;
}

void solve(int start_column)
{
	int i, j;
	
	if(start_column == n && !isfinish)
	{
		isfinish = true;
		for(i=0; i<n; i++)
		{
			printf("%d ", place[i] + 1);
		}
		printf("\n");
		return;
	}
	
	if(!isfinish)
		for(i=0; i<n; i++)
		{
			for(j=0; j<start_column; j++)
			{
				if(place[j] == i || abs(place[j] - i) == abs(j - start_column))
				{
					break;
				}
			}
			
			if(j == start_column)
			{
				place[start_column] = i;
				solve(start_column+1);
			}
		}
	else
		return;
}
