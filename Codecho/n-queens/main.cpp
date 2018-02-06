#include <cstdio>
#include <cstring>

int n;
//���ڴ洢ÿһ���ʺ��λ��
int place[300];
int abs(int a);
void solve(int start_line);

int main(void)
{
	while(scanf("%d", &n) != EOF)
	{
		if(n == 0)
			break;
		
		solve(0);
	}
	
	return 0;
}
//�����ֵ�ĺ���
int abs(int a)
{
	return (a < 0)?(-a):a;
}

/*
�������ĺ��� 
start_line��ʾ���Ϊstart_line��һ�еķ���
*/ 
void solve(int start_line)
{
	int i, j;
	
	//������һ���Ѿ������ϣ������������������ݹ�
	if(start_line == n)
	{
		for(i=0; i<n; i++)
		{
			printf("%d ", place[i] + 1);
		}
		printf("\n");
		return;
	}
	
	//i����ɨ��ÿһ�У�������start_line��һ�е��������
	for(i=0; i<n; i++)
	{
		//��ǰ���Ѿ����źõĻʺ���б������Ӷ��ж����λ��(i)�Ƿ����
		for(j=0; j<start_line; j++)
		{
			/*
			||ǰ��������ж��»ʺ����Ѿ����źõĻʺ��Ƿ���ͬһ��
			||����������ж��»ʺ����Ѿ����źõĻʺ��Ƿ��������ε�һ���Խ����� 
			��ͨ�����ݾ����Ƿ�������жϣ�
			��������Ŀ�����ķ���Ҫ�����
			*/ 
			if(place[j] == i || abs(place[j] - i) == abs(j - start_line))
			{
				break;
			}
		}
		
		//�ж��Ƿ�������������
		if(j == start_line)
		{
			//��¼�»ʺ��λ��
			place[start_line] = i;
			//����һ�н������
			solve(start_line+1);
		}
	}
}
