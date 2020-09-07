//==========================
//程序名称：推箱子 
//制作人：LinJ 
//版本号：1.0
//创建时间：2020.9.6
//上次修改时间：2020.9.7 11:47
//总制作天数：2
//特别鸣谢: https://blog.csdn.net/qq_40630246/article/details/80024781?utm_medium=distribute.pc_relevant.none-task-blog-title-3&spm=1001.2101.3001.4242
//==========================

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void showIndex();
void choose();
void game(int m);

// 全局变量
 
int p_x, p_y;	// 人位置
int pace; // 步数 
int Map_width[3] = {8, 9, 11};
int Map_height[3] = {8, 9, 7};

//关卡地图 
//8 8  9 9  7 10
//0:空地,1:墻,3:目的地,4:箱子,5:人,7:在目的地的箱子,8:在目的地的人 
int Map[3][11][11]= {{{0,0,1,1,1,0,0,0},{0,0,1,3,1,0,0,0},{0,0,1,0,1,1,1,1},{1,1,1,4,0,4,3,1},
    									{1,3,0,4,5,1,1,1},{1,1,1,1,4,1,0,0},{0,0,0,1,3,1,0,0},{0,0,0,1,1,1,0,0}},
										{{1,1,1,1,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,4,4,1,0,1,1,1},{1,5,4,0,1,0,1,3,1},
    									{1,1,1,0,1,1,1,3,1},{0,1,1,0,0,0,0,3,1},{0,1,0,0,0,1,0,0,1},{0,1,0,0,0,1,1,1,1},{0,1,1,1,1,1,0,0,0}},
    								{{0,1,1,1,1,1,1,1,0,0},{0,1,0,0,0,0,0,1,1,1},{1,1,4,1,1,1,0,0,0,1},{1,5,0,0,4,0,0,4,0,1},
    									{1,0,3,3,1,0,4,0,1,1},{1,1,3,3,1,0,0,0,1,0},{0,1,1,1,1,1,1,1,1,0}} 
};

int main() {
	// 隐藏光标信息 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);//获取光标信息
	cci.bVisible = FALSE;//隐藏光标
	SetConsoleCursorInfo(hOut, &cci);//设置光标信息
	
	//设定窗口信息 
	system("title 推箱子1.0");//设定窗口名称
	system("mode con cols=55 lines=30");//设定窗口大小
	
	// 显示主菜单 
	showIndex();
}

void showIndex() {
	char buf;
	int m = 0;
	char str[2][20] = {
		"[ ] 开始游戏",
		"[ ] 退出游戏"
	};
	
	while(1) {
		system("cls");
		
		str[m][1] = '>';
		
		printf("\n\n\n\t       主        菜        单\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
    printf("\n\t\t       推箱子\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("         ------------------------------------\n\n\n");
    printf("\t\t   %s\n\n\n", str[0]);
    printf("\t\t   %s\n\n\n\n", str[1]);
    printf("         ------------------------------------\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
    printf("\t     W/↑:上移        S/↓:下移\n\n");
    printf("\t    ENTER:进入\n\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("\t\t    powered by C");
		
		fflush(stdin);	// 清空输入流
		switch(getch()) {
			case 'W':
			case 'w':
			case 72:
				if(m == 1) {
					str[1][1] = ' ';
					m -= 1;
				}
				break;
			
			case 's':
			case 'S':
			case 80:
				if(m == 0) {
					str[0][1] = ' ';
					m += 1;
				}
				break;
			
			case '\r':
				if(m == 0) choose();
				else exit(0);
				break;
		}
	}
}

void choose() {
	char buf;
	int m = 3;
	char str[4][20] = {
		"[ ] 第 一 关",
		"[ ] 第 二 关", 
		"[ ] 第 三 关",
		"[ ] 返回主菜单"
	};
	
	while(1) {
		system("cls");
		
		str[m][1] = '>';
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		printf("\n\n\n\t        关    卡    选    择\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
    printf("\n\t\t       推箱子\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("         ------------------------------------\n\n");
    printf("\t\t   %s\n\n", str[0]);
    printf("\t\t   %s\n\n", str[1]);
    printf("\t\t   %s\n\n", str[2]);
    printf("\t\t   %s\n\n", str[3]);
    printf("         ------------------------------------\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
    printf("\t     W/↑:上移        S/↓:下移\n\n");
    printf("\t    ENTER:进入\n\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("\t\t    powered by C");
		
		fflush(stdin);	// 清空输入流
		switch(getch()) {
			case 'W':
			case 'w':
			case 72:
				if(m != 0) {
					str[m][1] = ' ';
					m -= 1;
				}
				break;
			
			case 's':
			case 'S':
			case 80:
				if(m != 3) {
					str[m][1] = ' ';
					m += 1;
				}
				break;
			
			case '\r':
				if(m == 3) showIndex();
				else game(m);
				break;
		}
	}
}

void exitGame(int i) {
	printf("暂停");
	char buf;
	int m = 0;
	char str[3][20] = {
		"[ ] 继续游戏",
		"[ ] 重新开始", 
		"[ ] 返回关卡选择"
	};
	
	while(1) {
		system("cls");
		
		str[m][1] = '>';
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
		printf("\n\n\n\t       退    出    游    戏   ?\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
    printf("\n\t\t       推箱子\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("         ------------------------------------\n\n");
    printf("\t\t   %s\n\n", str[0]);
    printf("\t\t   %s\n\n", str[1]);
    printf("\t\t   %s\n\n", str[2]);
    printf("         ------------------------------------\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
    printf("\t     W/↑:上移        S/↓:下移\n\n");
    printf("\t    ENTER:进入\n\n\n\n\n");
		
		fflush(stdin);	// 清空输入流
		switch(getch()) {
			case 'W':
			case 'w':
			case 72:
				if(m != 0) {
					str[m][1] = ' ';
					m -= 1;
				}
				break;
			
			case 's':
			case 'S':
			case 80:
				if(m != 2) {
					str[m][1] = ' ';
					m += 1;
				}
				break;
			
			case '\r':
				if(m == 0) return;
				else if(m == 1) game(i);
				else if(m == 2) choose();
				break;
		}
	}
}

int drawMap(int Map1[][10], int c) {
	int sum = 0;
	int width = Map_width[c], height = Map_height[c];; 
	
	printf("\n\n\n");
  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_BLUE);
  printf("\t\t     第  %d  关\n\n\n\n", c + 1);
  for(int i=0; i < height; i++) {
    printf("\t\t   ");
    for(int j = 0; j < width; j++) {
      switch(Map1[i][j]) {
      	case 0: // 空地
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	        printf("  ");
	        break;
        case 1: // 墻
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
          printf("■");
          break;
        case 3: // 目的地
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
          printf("☆");
          break;
        case 4: // 箱子
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
          printf("□");
          sum++; 
          break;
      	case 5: // 人
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
          printf("♀");
          p_x = i;
          p_y = j;
          break;
        case 7: // 在目的地的箱子
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
          printf("★");
          break;
        case 8: // 在目的地的人
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
          printf("♀");
          p_x = i;
          p_y = j;
          break;
      }
    }
    printf("\n");
  }
    
  if(sum) return 0;
	return 1;
}


void game(int m) {
	int Map1[10][10];
	
	for(int i = 0; i < Map_height[m]; i++) {
		for(int j = 0; j < Map_width[m]; j++) {
			Map1[i][j] = Map[m][i][j];
		}
	}
	int p;
	pace = 0;
	
	while(1) {
		system("cls");
		
		p = drawMap(Map1, m);
	
		printf("\n\t\t     当前步数为%d步。", pace);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN |FOREGROUND_INTENSITY);
	  printf("\n\n     按ESC键退出此游戏，之后重新进入从该关重新开始。\n");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
	  printf("\n\t   开始游戏前输入法请锁定成英文大写。\n\n");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
	  printf("\t     W/↑:上移        S/↓:下移\n\n");
	  printf("\t     A/←:左移        D/→:右移\n\n\n");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
	  
	  if(p) {
	  	printf("\t\t    恭 喜 通 关！\n");
	  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			printf("\n按任意键继续...");
			char buf;
			buf = getch();
			choose();	
		}
		
		fflush(stdin);	// 清空输入流
		switch(getch()) {
			case 224: break;
			case 'w':
			case 'W':
			case 72:
				if(Map1[p_x - 1][p_y] == 1) {
					break;
				}
				if(Map1[p_x - 1][p_y] == 4 || Map1[p_x - 1][p_y] == 7) {
					if(Map1[p_x - 2][p_y] == 1 || Map1[p_x - 2][p_y] == 4 || Map1[p_x - 2][p_y] == 7) {
						break;
					}
					Map1[p_x - 2][p_y] += 4;
					Map1[p_x - 1][p_y] -= 4;
				}
				Map1[p_x - 1][p_y] += 5;
				Map1[p_x][p_y] -= 5;
				p_x -= 1;
				pace += 1;
				break;
			case 80:
			case 's':
			case 'S':
				if(Map1[p_x + 1][p_y] == 1) {
					break;
				}
				if(Map1[p_x + 1][p_y] == 4 || Map1[p_x + 1][p_y] == 7) {
					if(Map1[p_x + 2][p_y] == 1 || Map1[p_x + 2][p_y] == 4 || Map1[p_x + 2][p_y] == 7) {
						break;
					}
					Map1[p_x + 2][p_y] += 4;
					Map1[p_x + 1][p_y] -= 4;
				}
				Map1[p_x + 1][p_y] += 5;
				Map1[p_x][p_y] -= 5;
				p_x += 1;
				pace += 1;
				break;
			case 'a':
			case 'A':
			case 75:
				if(Map1[p_x][p_y - 1] == 1) {
					break;
				}
				if(Map1[p_x][p_y - 1] == 4 || Map1[p_x][p_y - 1] == 7) {
					if(Map1[p_x][p_y - 2] == 1 || Map1[p_x][p_y - 2] == 4 || Map1[p_x][p_y - 2] == 7) {
						break;
					}
					Map1[p_x][p_y - 2] += 4;
					Map1[p_x][p_y - 1] -= 4;
				}
				Map1[p_x][p_y - 1] += 5;
				Map1[p_x][p_y] -= 5;
				p_y -= 1;
				pace += 1;
				break;
			case 'd':
			case 'D':
			case 77:
				if(Map1[p_x][p_y + 1] == 1) {
					break;
				}
				if(Map1[p_x][p_y + 1] == 4 || Map1[p_x][p_y + 1] == 7) {
					if(Map1[p_x][p_y + 2] == 1 || Map1[p_x][p_y + 2] == 4 || Map1[p_x][p_y + 2] == 7) {
						break;
					}
					Map1[p_x][p_y + 2] += 4;
					Map1[p_x][p_y + 1] -= 4;
				}
				Map1[p_x][p_y + 1] += 5;
				Map1[p_x][p_y] -= 5;
				p_y += 1;
				pace += 1;
				break;
			case '\033': exitGame(m); break;
		}
	} 
}
