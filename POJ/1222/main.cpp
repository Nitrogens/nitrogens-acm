#include <cstdio>
#include <cstring>

//读入的原始数据（保持不变）
char original_data[6]; 
//每次操作时使用的数据（如果不明白的话看后面的代码就能懂了）
char data[6]; 
//按按钮的方式（即结果）
char switchs[6];
//改变某个二进制位为指定的数
void bit_change(char & src, int pos, int content);
//反转某个二进制位(1->0, 0->1)
void bit_reverse(char & src, int pos);
//获取某个二进制位
char bit_get(char & src, int pos);
int main(void)
{
	int n, i, j, k, l, temp;
	char switchs_line;	//用于临时存储每行的操作
	scanf("%d", &n);
	
	for(i=0; i<n; i++)
	{
		//清空数组
		memset(original_data, 0, sizeof(original_data));
		memset(data, 0, sizeof(data));
		memset(switchs, 0, sizeof(switchs));
		
		//一位一位读入数据
		for(j=0; j<5; j++)
		{
			for(k=0; k<6; k++)
			{
				scanf("%d", &temp);
				bit_change(original_data[j], k, temp);
			}
		}
		
		//对每一种按按钮的方式进行枚举（6位，最大为111111，即63） 
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
						//按照规则，对一行中的灯进行操作
						bit_reverse(data[l], k);
						if(k > 0)
							bit_reverse(data[l], k-1);
						if(k < 5)
							bit_reverse(data[l], k+1);
					}
				}
				//对下一行的灯进行操作
				//如果不理解，可以仔细想想位运算的内部原理
				if(l < 4)
					data[l+1] ^= switchs_line;
				switchs[l] = switchs_line;	//存储操作
				/* 
				为了让上一行的灯全部熄灭，下一行的操作要与上一行的灯一致
				同样地，如果不理解，可以仔细想想位运算的内部原理 
				但是这里的位运算不需要再进行，因为已经保证了上一行的灯都是熄灭的
				而结果中只需要按按钮的方式
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
改变某个二进制位为指定的数
同样地，如果不理解，可以仔细想想位运算的内部原理 
src表示要改变的一串二进制数
pos表示位（从0开始） 
content表示那个指定的数（0或1） 
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
反转某个二进制位(1->0, 0->1)
同样地，如果不理解，可以仔细想想位运算的内部原理 
src表示要改变的一串二进制数
pos表示位（从0开始） 
*/ 
void bit_reverse(char & src, int pos)
{
	src ^= (1 << pos);
}
/* 
获取某个二进制位
同样地，如果不理解，可以仔细想想位运算的内部原理 
src表示要操作的一串二进制数
pos表示位（从0开始） 
*/ 
char bit_get(char & src, int pos)
{
	return (src >> pos) & 1;
}
