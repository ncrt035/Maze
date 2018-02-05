#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//���O���[�o���ȂQ�����z��maze[10][10]���`
int maze[10][10]={{0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0},
				  {0,0,0,0,0,0,0,0,0,0}
				 };

void MAZE_DEF()
{
	int i,j,k;
	int LU[3][5][5] = 
	{		//[0]
		{
			{1,1,1,1,1},
			{1,0,0,0,0},
			{1,0,1,1,1},
			{1,2,1,1,1},
			{1,0,1,0,0}
		},
			//[1]
		{
			{1,1,1,1,1},
			{1,0,0,0,0},
			{1,0,1,0,1},
			{1,0,1,4,2},
			{1,0,1,0,1}
		},	//[2]
		{
			{1,1,1,1,1},
			{1,0,0,0,0},
			{1,1,1,0,1},
			{1,0,0,0,1},
			{1,0,1,0,0}
		}
	};
	int RU[3][5][5] = 
	{
		//[0]
		{
			{1,1,1,1,1},
			{0,1,2,0,1},
			{0,1,1,0,1},
			{0,1,1,0,1},
			{4,0,0,0,1}
	
		},
		//[1]
		{
			{1,1,1,1,1},
			{0,0,0,0,1},
			{1,1,1,0,1},
			{0,2,4,0,1},
			{1,1,1,0,1}
		},
		//[2]
		{
			{1,1,1,1,1},
			{0,1,0,1,1},
			{0,2,0,0,1},
			{1,1,1,0,1},
			{0,0,0,0,1}
		},
	};
	int LD[3][5][5] = 
	{
		//[0]
		{
			{1,0,1,1,1},
			{1,0,1,1,1},
			{1,0,2,0,1},
			{1,1,1,0,0},
			{1,1,1,1,1}
		},
		//[1]
		{
			{1,0,1,0,1},
			{1,0,1,2,0},
			{1,0,1,1,1},
			{1,0,0,0,0},
			{1,1,1,1,1}
		},
		//[2]
		{
			{1,0,1,0,1},
			{1,0,0,0,0},
			{1,0,1,0,1},
			{1,1,1,2,0},
			{1,1,1,1,1}
		},
	};
	int RD[3][5][5] = 
	{
		//[0]
		{
			{1,1,1,0,1},
			{3,1,1,0,1},
			{0,1,1,0,1},
			{0,0,0,0,1},
			{1,1,1,1,1}
		},
		//[1]
		{
			{1,1,1,0,1},
			{1,3,1,0,1},
			{1,0,1,0,1},
			{0,4,0,0,1},
			{1,1,1,1,1}
		},
		//[2]
		{
			{1,0,0,0,1},
			{1,0,1,0,1},
			{0,2,1,0,1},
			{0,1,1,3,1},
			{1,1,1,1,1}
		},
	};
	
	srand((unsigned)time(NULL));

	k = rand()%3;
	for(i=0; i<5; i++)
	{
		for(j=0; j<5; j++)
		{
			maze[i][j] = LU[k][i][j];
		}
	}
	k = rand()%3;
	for(i=0; i<5; i++)
	{
		for(j=5; j<10; j++)
		{
			maze[i][j] = RU[k][i][j-5];
		}
	}
	k = rand()%3;
	for(i=5; i<10; i++)
	{
		for(j=0; j<5; j++)
		{
			maze[i][j] = LD[k][i-5][j];
		}
	}
	k = rand()%3;
	for(i=5; i<10; i++)
	{
		for(j=5; j<10; j++)
		{
			maze[i][j] = RD[k][i-5][j-5];
		}
	}
}

void main(void)
{
	char move;				//�L�[�{�[�h����̓��͎擾�p�ϐ�
	int gold;				//�������Ǘ�
	int g_gold;				//�E�����p�ϐ�
	int i,j;				//�s��p�Y��
	int player[2];			//�v���C���ʒu�Ǘ�
	int enemy[2];			//�G�����ʒu
	int e_life;				//�G�̐����Ǘ�
	int floor;				//�K�w�Ǘ�
	int clear;				//�K�w�N���A�Ǘ�
	int game_over;			//�Q�[���I�[�o�[�̔���
	int end;

	srand((unsigned)time(NULL));

	//���ϐ������l��`
	gold      = 0;

	e_life	  = 1;
	floor     = 1;
	clear     = 0;
	game_over = 0;

	while(floor < 6)
	{
		player[0] = 1;
		player[1] = 1;
		e_life    = 1;
		enemy[0]  = 8;
		enemy[1]  = 8;

		MAZE_DEF();



		while(clear != 1)
		{
			printf("B%dF    ������%5d�~\n", floor, gold);

			for(i=0; i<10; i++)				//���H�}�b�v�̕\��
			{
				for(j=0; j<10; j++)
				{
					
					if(e_life != 0 && i == enemy[0] && j == enemy[1])
					{
						printf("��");      //�G
					}
					else if(i == player[0] && j == player[1])
					{
						printf("��");      //�v���C��
					}
					else if(maze[i][j] == 1)
					{
						printf("��");      //��
					}
					else if(maze[i][j] == 2)
					{
						printf("��");      //����
					}
					else if(maze[i][j] == 4)
					{
						printf("�w");		//�
					}
					else if(maze[i][j] == 3)
					{
						if(floor == 5)
						{
							printf("�f");	//B5F�Ȃ�S�[��
						}
						else
						{
							printf("�e");   //����ȊO�Ȃ牺��K�i
						}
					}
					
					else
					{
						printf("�@");      //��
					}
				}
				printf("\n");
			}
			
			 //���󋵂ɉ��������b�Z�[�W�̕\���ƕ���
			if(player[0] == enemy[0] && player[1] == enemy[1])  //�G�ɏP��ꂽ�ꍇ
			{
					game_over = 1;
			}
			else                             
			{}

			switch(maze[player[0]][player[1]])
			{
				case 2:								//�������E�����ꍇ
					g_gold = (rand()%9+1)*100;
					printf("%d�~����肵�܂����B", g_gold);
					gold = g_gold + gold;
					maze[player[0]][player[1]] = 0;
					break;

				case 3:					//�K�i�ɓ��B�����ꍇ
						floor += 1;
						clear  = 1;
					
					break;

				case 4:					//㩂𓥂񂾏ꍇ
					game_over = 1;
					break;

				default:
					break;
			}

			if(clear == 1)				//�K�i�ɓ��B�����ꍇ�̏����̑���				
			{
				clear = 0;
				system("cls");
				break;
			}
			else
			{}
			if(game_over == 1)
			{
				break;
			}
			else
			{}

											//���v���C���̓����M
			move = getch();					//�L�[�{�[�h������͂��擾
					
			if(move == 50 && maze[player[0]+1][player[1]] != 1) //50��2�̃A�X�L�[�R�[�h
			{
				player[0] = player[0]+1;	
			}
			else if(move == 52 && maze[player[0]][player[1]-1] != 1)
			{
				player[1] = player[1]-1;
			}
			else if(move == 54 && maze[player[0]][player[1]+1] != 1)
			{
				player[1] = player[1]+1;
			}
			else if(move == 56 && maze[player[0]-1][player[1]] != 1)
			{
				player[0] = player[0]-1;
			}			
			else								
			{}

			if(e_life == 1)
			{
				switch( move )
				{
				case 50:
				case 52:
				case 54:
				case 56:
					if(enemy[0] > player[0] && maze[enemy[0]-1][enemy[1]] != 1)  
					{
						 enemy[0] -= 1;
					}
					else if(enemy[0] < player[0] && maze[enemy[0]+1][enemy[1]] != 1)
					{
						 enemy[0] += 1;
					}																			
					else if(enemy[1] > player[1] && maze[enemy[0]][enemy[1]-1] != 1)
					{
						 enemy[1] -= 1;
					}
					else if(enemy[1] < player[1] && maze[enemy[0]][enemy[1]+1] != 1)
					{
						 enemy[1] += 1;
					}
					else
					{}
					break;
				}
			}
			else{}

			if(maze[enemy[0]][enemy[1]] == 4)	//�G��㩂𓥂񂾂Ƃ��̏���(����)
			{
				e_life					 = 0;
				maze[enemy[0]][enemy[1]] = 0;
				enemy[0]				 = 0;
				enemy[1]				 = 0;
			}
			else{}

		

			system("cls");

		}
		if(game_over == 1)
		{
			break;
		}
	}

	if(game_over == 1)
	{
		puts("�c�O�ł����B");
		puts("�Q�[���I�[�o�[�ł��B");
		printf("���B�K : B%5dF\n", floor);
		printf("������ : %5d�~\n", gold);

	}
	else
	{
		puts("+-----------------------+");
		puts("| ���߂łƂ��������܂�! |");
		puts("|   �Q�[���N���A�ł��B  |");
		puts("+-----------------------+");

		printf("������ : %5d�~\n", gold);
	}
	puts("�I�����܂��B0����͂��Ă��������B");
	scanf("%d", &end);
}