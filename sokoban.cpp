//==========================
//�������ƣ������� 
//�����ˣ�LinJ 
//�汾�ţ�1.0
//����ʱ�䣺2020.9.6
//�ϴ��޸�ʱ�䣺2020.9.7 11:47
//������������2
//�ر���л: https://blog.csdn.net/qq_40630246/article/details/80024781?utm_medium=distribute.pc_relevant.none-task-blog-title-3&spm=1001.2101.3001.4242
//==========================

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

void showIndex();
void choose();
void game(int m);

// ȫ�ֱ���
 
int p_x, p_y;	// ��λ��
int pace; // ���� 
int Map_width[3] = {8, 9, 11};
int Map_height[3] = {8, 9, 7};

//�ؿ���ͼ 
//8 8  9 9  7 10
//0:�յ�,1:��,3:Ŀ�ĵ�,4:����,5:��,7:��Ŀ�ĵص�����,8:��Ŀ�ĵص��� 
int Map[3][11][11]= {{{0,0,1,1,1,0,0,0},{0,0,1,3,1,0,0,0},{0,0,1,0,1,1,1,1},{1,1,1,4,0,4,3,1},
    									{1,3,0,4,5,1,1,1},{1,1,1,1,4,1,0,0},{0,0,0,1,3,1,0,0},{0,0,0,1,1,1,0,0}},
										{{1,1,1,1,1,0,0,0,0},{1,0,0,0,1,0,0,0,0},{1,0,4,4,1,0,1,1,1},{1,5,4,0,1,0,1,3,1},
    									{1,1,1,0,1,1,1,3,1},{0,1,1,0,0,0,0,3,1},{0,1,0,0,0,1,0,0,1},{0,1,0,0,0,1,1,1,1},{0,1,1,1,1,1,0,0,0}},
    								{{0,1,1,1,1,1,1,1,0,0},{0,1,0,0,0,0,0,1,1,1},{1,1,4,1,1,1,0,0,0,1},{1,5,0,0,4,0,0,4,0,1},
    									{1,0,3,3,1,0,4,0,1,1},{1,1,3,3,1,0,0,0,1,0},{0,1,1,1,1,1,1,1,1,0}} 
};

int main() {
	// ���ع����Ϣ 
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut, &cci);//��ȡ�����Ϣ
	cci.bVisible = FALSE;//���ع��
	SetConsoleCursorInfo(hOut, &cci);//���ù����Ϣ
	
	//�趨������Ϣ 
	system("title ������1.0");//�趨��������
	system("mode con cols=55 lines=30");//�趨���ڴ�С
	
	// ��ʾ���˵� 
	showIndex();
}

void showIndex() {
	char buf;
	int m = 0;
	char str[2][20] = {
		"[ ] ��ʼ��Ϸ",
		"[ ] �˳���Ϸ"
	};
	
	while(1) {
		system("cls");
		
		str[m][1] = '>';
		
		printf("\n\n\n\t       ��        ��        ��\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
    printf("\n\t\t       ������\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("         ------------------------------------\n\n\n");
    printf("\t\t   %s\n\n\n", str[0]);
    printf("\t\t   %s\n\n\n\n", str[1]);
    printf("         ------------------------------------\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
    printf("\t     W/��:����        S/��:����\n\n");
    printf("\t    ENTER:����\n\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("\t\t    powered by C");
		
		fflush(stdin);	// ���������
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
		"[ ] �� һ ��",
		"[ ] �� �� ��", 
		"[ ] �� �� ��",
		"[ ] �������˵�"
	};
	
	while(1) {
		system("cls");
		
		str[m][1] = '>';
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
		printf("\n\n\n\t        ��    ��    ѡ    ��\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
    printf("\n\t\t       ������\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("         ------------------------------------\n\n");
    printf("\t\t   %s\n\n", str[0]);
    printf("\t\t   %s\n\n", str[1]);
    printf("\t\t   %s\n\n", str[2]);
    printf("\t\t   %s\n\n", str[3]);
    printf("         ------------------------------------\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
    printf("\t     W/��:����        S/��:����\n\n");
    printf("\t    ENTER:����\n\n\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("\t\t    powered by C");
		
		fflush(stdin);	// ���������
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
	printf("��ͣ");
	char buf;
	int m = 0;
	char str[3][20] = {
		"[ ] ������Ϸ",
		"[ ] ���¿�ʼ", 
		"[ ] ���عؿ�ѡ��"
	};
	
	while(1) {
		system("cls");
		
		str[m][1] = '>';
		
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
		printf("\n\n\n\t       ��    ��    ��    Ϸ   ?\n\n");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
    printf("\n\t\t       ������\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
  	printf("         ------------------------------------\n\n");
    printf("\t\t   %s\n\n", str[0]);
    printf("\t\t   %s\n\n", str[1]);
    printf("\t\t   %s\n\n", str[2]);
    printf("         ------------------------------------\n\n\n");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
    printf("\t     W/��:����        S/��:����\n\n");
    printf("\t    ENTER:����\n\n\n\n\n");
		
		fflush(stdin);	// ���������
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
  printf("\t\t     ��  %d  ��\n\n\n\n", c + 1);
  for(int i=0; i < height; i++) {
    printf("\t\t   ");
    for(int j = 0; j < width; j++) {
      switch(Map1[i][j]) {
      	case 0: // �յ�
	        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
	        printf("  ");
	        break;
        case 1: // ��
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
          printf("��");
          break;
        case 3: // Ŀ�ĵ�
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_GREEN);
          printf("��");
          break;
        case 4: // ����
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE|FOREGROUND_RED);
          printf("��");
          sum++; 
          break;
      	case 5: // ��
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_BLUE);
          printf("��");
          p_x = i;
          p_y = j;
          break;
        case 7: // ��Ŀ�ĵص�����
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
          printf("��");
          break;
        case 8: // ��Ŀ�ĵص���
          SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED);
          printf("��");
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
	
		printf("\n\t\t     ��ǰ����Ϊ%d����", pace);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN |FOREGROUND_INTENSITY);
	  printf("\n\n     ��ESC���˳�����Ϸ��֮�����½���Ӹù����¿�ʼ��\n");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
	  printf("\n\t   ��ʼ��Ϸǰ���뷨��������Ӣ�Ĵ�д��\n\n");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_GREEN | FOREGROUND_RED |FOREGROUND_INTENSITY);
	  printf("\t     W/��:����        S/��:����\n\n");
	  printf("\t     A/��:����        D/��:����\n\n\n");
	  SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_RED|FOREGROUND_INTENSITY);
	  
	  if(p) {
	  	printf("\t\t    �� ϲ ͨ �أ�\n");
	  	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),FOREGROUND_INTENSITY|FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_BLUE);
			printf("\n�����������...");
			char buf;
			buf = getch();
			choose();	
		}
		
		fflush(stdin);	// ���������
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
