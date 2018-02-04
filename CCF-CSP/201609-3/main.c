#include <stdio.h>
#include <string.h>
int main(void)
{
	int hero_hp[2], summon_attack[2][7], summon_hp[2][7], summon_position[2][7];
	int N, i, j, k, temp_position, temp_attack, temp_health, temp_attacker, temp_defender, temp;
	int status = 0;	//先手 
	int summon_sum[2];
	
	char string[100];
	const char delims[] = "\040";
	char *temp_command;
	
	hero_hp[0] = 30;
	hero_hp[1] = 30;
	
	summon_sum[0] = 0;
	summon_sum[1] = 0;
	
	for(i=0; i<2; i++)
	{
		for(j=0; j<7; j++)
		{
			summon_position[i][j] = 0;
		}
	}
	
	scanf("%d", &N);
	getchar();
	
	for(i=0; i<N; i++)
	{
		gets(string);
		temp_command = strtok(string, delims);
		
		
		if( strcmp(temp_command, "end") == 0 )	//字符串比较使用strcmp函数，0表示一致 
		{
			status = 1-status;
		}
		
		if( strcmp(temp_command, "summon") == 0 )
		{
			temp_position = atoi(strtok(NULL, delims));
			temp_attack = atoi(strtok(NULL, delims));
			temp_health = atoi(strtok(NULL, delims));
				
			if (summon_position[status][temp_position-1] == 0)
			{
				summon_position[status][summon_sum[status]] = 1;
				summon_hp[status][summon_sum[status]] = temp_health;
				summon_attack[status][summon_sum[status]] = temp_attack;
			}
			else
			{
				for(j=summon_sum[status]-1; j>=temp_position-1; j--)
				{
					summon_position[status][j+1] = 1;
					summon_hp[status][j+1] = summon_hp[status][j];
					summon_attack[status][j+1] = summon_attack[status][j];
				}
				summon_position[status][temp_position-1] = 1;
				summon_hp[status][temp_position-1] = temp_health;
				summon_attack[status][temp_position-1] = temp_attack;
			}
				
			summon_sum[status]++;
		}
		
		if( strcmp(temp_command, "attack") == 0 )
		{
			temp_attacker = atoi(strtok(NULL, delims));
			temp_defender = atoi(strtok(NULL, delims));
				
			if(temp_defender != 0)
			{
				summon_hp[status][temp_attacker-1] -= summon_attack[1-status][temp_defender-1];
				summon_hp[1-status][temp_defender-1] -= summon_attack[status][temp_attacker-1];
				
				if(summon_hp[status][temp_attacker-1] <= 0)
				{
					for(j=temp_attacker-1; j<=summon_sum[status]-2; j++)
					{
						summon_position[status][j] = 1;
						summon_hp[status][j] = summon_hp[status][j+1];
						summon_attack[status][j] = summon_attack[status][j+1];
					}
					
					summon_position[status][summon_sum[status]-1] = 0;
					summon_hp[status][summon_sum[status]-1] = 0;
					summon_attack[status][summon_sum[status]-1] = 0;
					
					summon_sum[status]--;
				}
				
				if(summon_hp[1-status][temp_defender-1] <= 0)
				{
					for(j=temp_defender-1; j<=summon_sum[1-status]-2; j++)
					{
						summon_position[1-status][j] = 1;
						summon_hp[1-status][j] = summon_hp[1-status][j+1];
						summon_attack[1-status][j] = summon_attack[1-status][j+1];
					}
					
					summon_position[1-status][summon_sum[1-status]-1] = 0;
					summon_hp[1-status][summon_sum[1-status]-1] = 0;
					summon_attack[1-status][summon_sum[1-status]-1] = 0;
					
					summon_sum[1-status]--;
				}
			}
			else
			{
				hero_hp[1-status] -= summon_attack[status][temp_attacker-1];
				if (hero_hp[1-status] <= 0)
					break;
			}
	
		}
		
		//setbuf(stdin, NULL);	//清空键盘缓存区 
		
		

	}
	
	if(hero_hp[0] <= 0)
	{
		printf("%d\n", -1);
	}
	if(hero_hp[1] <= 0)
	{
		printf("%d\n", 1);
	}
	if((hero_hp[0] > 0)&&(hero_hp[1] > 0))
	{
		printf("%d\n", 0);
	}
	
	
	printf("%d\n", hero_hp[0]);
	
	if (summon_sum[0] == 0)
	{
		printf("%d\n", summon_sum[0]);
	}
	else
	{
		printf("%d", summon_sum[0]);
		for(i=0; i<summon_sum[0]; i++)
		{
			printf(" %d", summon_hp[0][i]);
		}
		printf("\n");
	}
	
	printf("%d\n", hero_hp[1]);
	
	if (summon_sum[1] == 0)
	{
		printf("%d", summon_sum[1]);
	}
	else
	{
		printf("%d", summon_sum[1]);
		for(i=0; i<summon_sum[1]; i++)
		{
			printf(" %d", summon_hp[1][i]);
		}
	}
	
	return 0;
}
