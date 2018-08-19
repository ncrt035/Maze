#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//▼グローバルな２次元配列maze[10][10]を定義
int maze[10][10]={
								{0,0,0,0,0,0,0,0,0,0},
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
	char move;				//キーボードからの入力取得用変数
	int gold;				//所持金管理
	int g_gold;				//拾得金用変数
	int i,j;				//行列用添字
	int player[2];			//プレイヤ位置管理
	int enemy[2];			//敵初期位置
	int e_life;				//敵の生死管理
	int floor;				//階層管理
	int clear;				//階層クリア管理
	int game_over;			//ゲームオーバーの判定
	int end;

	srand((unsigned)time(NULL));

	//諸変数初期値定義
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
			printf("B%dF    所持金%5d円\n", floor, gold);

			for(i=0; i<10; i++)				//迷路マップの表示
			{
				for(j=0; j<10; j++)
				{

					if(e_life != 0 && i == enemy[0] && j == enemy[1])
					{
						printf("▲");      //敵
					}
					else if(i == player[0] && j == player[1])
					{
						printf("●");      //プレイヤ
					}
					else if(maze[i][j] == 1)
					{
						printf("■");      //壁
					}
					else if(maze[i][j] == 2)
					{
						printf("＄");      //お金
					}
					else if(maze[i][j] == 4)
					{
						printf("Ｘ");		//罠
					}
					else if(maze[i][j] == 3)
					{
						if(floor == 5)
						{
							printf("Ｇ");	//B5Fならゴール
						}
						else
						{
							printf("Ｆ");   //それ以外なら下り階段
						}
					}

					else
					{
						printf("　");      //床
					}
				}
				printf("\n");
			}

			 //▼状況に応じたメッセージの表示と分岐
			if(player[0] == enemy[0] && player[1] == enemy[1])  //敵に襲われた場合
			{
					game_over = 1;
			}
			else
			{}

			switch(maze[player[0]][player[1]])
			{
				case 2:								//お金を拾った場合
					g_gold = (rand()%9+1)*100;
					printf("%d円を入手しました。", g_gold);
					gold = g_gold + gold;
					maze[player[0]][player[1]] = 0;
					break;

				case 3:					//階段に到達した場合
						floor += 1;
						clear  = 1;

					break;

				case 4:					//罠を踏んだ場合
					game_over = 1;
					break;

				default:
					break;
			}

			if(clear == 1)				//階段に到達した場合の処理の続き
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

											//▼プレイヤの動作受信
			move = getch();					//キーボードから入力を取得

			if(move == 50 && maze[player[0]+1][player[1]] != 1) //50は2のアスキーコード
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

			if(maze[enemy[0]][enemy[1]] == 4)	//敵が罠を踏んだときの処理(消滅)
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
		puts("残念でした。");
		puts("ゲームオーバーです。");
		printf("到達階 : B%5dF\n", floor);
		printf("所持金 : %5d円\n", gold);

	}
	else
	{
		puts("+-----------------------+");
		puts("| おめでとうございます! |");
		puts("|   ゲームクリアです。  |");
		puts("+-----------------------+");

		printf("所持金 : %5d円\n", gold);
	}
	puts("終了します。0を入力してください。");
	scanf("%d", &end);
}
