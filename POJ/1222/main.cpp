#include <cstdio>
#include <cstring>

//�����ԭʼ���ݣ����ֲ��䣩
char original_data[6]; 
//ÿ�β���ʱʹ�õ����ݣ���������׵Ļ�������Ĵ�����ܶ��ˣ�
char data[6]; 
//����ť�ķ�ʽ���������
char switchs[6];
//�ı�ĳ��������λΪָ������
void bit_change(char & src, int pos, int content);
//��תĳ��������λ(1->0, 0->1)
void bit_reverse(char & src, int pos);
//��ȡĳ��������λ
char bit_get(char & src, int pos);
int main(void)
{
	int n, i, j, k, l, temp;
	char switchs_line;	//������ʱ�洢ÿ�еĲ���
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		//�������
		memset(original_data, 0, sizeof(original_data));
		memset(data, 0, sizeof(data));
		memset(switchs, 0, sizeof(switchs));
		
		//һλһλ��������
		for(j=0; j<5; j++)
		{
			for(k=0; k<6; k++)
			{
				scanf("%d", &temp);
				bit_change(original_data[j], k, temp);
			}
		}
		
		//��ÿһ�ְ���ť�ķ�ʽ����ö�٣�6λ�����Ϊ111111����63�� 
		for(j=0; j<64; j++)
		{
			switchs_line = j;
			memcpy(data, original_data, sizeof(original_data));
			for(l=0; l<5; l++)
			{
				for(k=0; k<6; k++)
				{
					if(bit_get(switchs_line, k))
					{
						//���չ��򣬶�һ���еĵƽ��в���
						bit_reverse(data[l], k);
						if(k > 0)
							bit_reverse(data[l], k-1);
						if(k < 5)
							bit_reverse(data[l], k+1);
					}
				}
				//����һ�еĵƽ��в���
				//�������⣬������ϸ����λ������ڲ�ԭ��
				if(l < 4)
					data[l+1] ^= switchs_line;
				switchs[l] = switchs_line;	//�洢����
				/* 
				Ϊ������һ�еĵ�ȫ��Ϩ����һ�еĲ���Ҫ����һ�еĵ�һ��
				ͬ���أ��������⣬������ϸ����λ������ڲ�ԭ�� 
				���������λ���㲻��Ҫ�ٽ��У���Ϊ�Ѿ���֤����һ�еĵƶ���Ϩ���
				�������ֻ��Ҫ����ť�ķ�ʽ
				*/ 
				switchs_line = data[l];
			}
			if(data[4] == 0)
			{
				printf("PUZZLE #%d\n", i+1);
				for(l=0; l<5; l++)
				{
					for(k=0; k<6; k++)
					{
						if(k == 0)
							printf("%d", bit_get(switchs[l], k));
						else
							printf(" %d", bit_get(switchs[l], k));
					}
					printf("\n");
				}
				break;
			}
		}
	}
	
	return 0;
}
/* 
�ı�ĳ��������λΪָ������
ͬ���أ��������⣬������ϸ����λ������ڲ�ԭ�� 
src��ʾҪ�ı��һ����������
pos��ʾλ����0��ʼ�� 
content��ʾ�Ǹ�ָ��������0��1�� 
*/  
void bit_change(char & src, int pos, int content)
{
	if(content)
	{
		src |= (1 << pos);
	}
	else
	{
		src &= ~(1 << pos);
	}
}
/* 
��תĳ��������λ(1->0, 0->1)
ͬ���أ��������⣬������ϸ����λ������ڲ�ԭ�� 
src��ʾҪ�ı��һ����������
pos��ʾλ����0��ʼ�� 
*/ 
void bit_reverse(char & src, int pos)
{
	src ^= (1 << pos);
}
/* 
��ȡĳ��������λ
ͬ���أ��������⣬������ϸ����λ������ڲ�ԭ�� 
src��ʾҪ������һ����������
pos��ʾλ����0��ʼ�� 
*/ 
char bit_get(char & src, int pos)
{
	return (src >> pos) & 1;
}
