#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "mylib.h"
using namespace std;

void ve_tuong(int xleft, int xright, int ytop, int ybot);
void ve_tuong_duong_ray();
void ve_nha_may();
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_dulieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);

void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua);
void them(int a[], int x);
void xoa(int a[], int vt);
bool kt_ran_cham_tuong(int x0, int y0);
bool kt_ran_cham_duoi(int toadox[], int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
bool kt_ran_duong_ray(int x0, int y0);
bool kt_ran_nha_may(int x0, int y0);
bool kt_duong_ray(int toadox[], int toadoy[]);
bool kt_nha_may(int toadox[], int toadoy[]);
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);
void xuatVaoFile(int score);
void xoacontro();

void che_do();
void map();
void HuongDan();

void printWelcome();
void printInfo();
void printLoadingBar();
void highlightMenu();

void normal(){
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	ve_tuong(10, 100, 1, 26);
	xoacontro();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	// kiem tra va tao qua
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;
    int check = 2;
	while(gameover == false){
		xoa_dulieu_cu(toadox, toadoy);
		// dieu khien
		if(kbhit()){
			char kitu = getch();
			if(kitu == -32){
				kitu = getch();
				if(kitu == 72 && check != 0)
					check = 1;
				else if(kitu == 80 && check != 1)
					check = 0;
				else if(kitu == 77 && check != 3)
					check = 2;
				else if(kitu == 75 && check != 2)
					check = 3;
			}
		}
		if(check == 0)
			y++;// di xuong
		else if(check == 1)
			y--;// di len
		else if(check == 2)
			x++;// di qua phai
		else if(check == 3)
			x--;// di qua trai
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		// kiem tra
	    if(gameover = kt_ran(toadox, toadoy)){
			SetColor(15);
			gotoXY(53, 12);
			printf("LOSE :((");
			gotoXY(50, 13);
			printf("Your score: %d", score);
			if(score>maxscore){
				maxscore = score;
				xuatVaoFile(maxscore);
			}	
			Sleep(1500);
			system("cls");
		}
		if (check == 1 || check == 0)
        	Sleep(50);
		else if (check == 2 || check == 3)
			Sleep(30);
	}
	_getch();
	return ;
}

void DuongRay(){
	bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	ve_tuong_duong_ray();
	xoacontro();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	// kiem tra va tao qua
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	while(gameover == false){
		xoa_dulieu_cu(toadox, toadoy);
		// dieu khien
		if(kbhit()){
			char kitu = getch();
			if(kitu == -32){
				kitu = getch();
				if(kitu == 72 && check != 0){
					check = 1;
				}
				else if(kitu == 80 && check != 1){
					check = 0;
				}
				else if(kitu == 77 && check != 3){
					check = 2;
				}
				else if(kitu == 75 && check != 2){
					check = 3;
				}
			}
		}
		if(check == 0){
			y++;// di xuong
		}
		else if(check == 1){
			y--;// di len
		}
		else if(check == 2){
			x++;// di qua phai
		}
		else if(check == 3){
			x--;// di qua trai
		}
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		// kiem tra
	    if(gameover = kt_duong_ray(toadox, toadoy)){
			SetColor(15);
			gotoXY(53, 12);
			printf("LOSE :((");
			gotoXY(50, 13);
			printf("Your score: %d", score);
			if(score>maxscore){
				maxscore = score;
				xuatVaoFile(maxscore);
			}	
			Sleep(1500);
			system("cls");
		}
		if (check == 1 || check == 0)
        	Sleep(100);
		else if (check == 2 || check == 3)
			Sleep(60);
	}
	_getch();
	return ;
}

void NhaMay(){
    bool gameover = false;
	int toadox[MAX], toadoy[MAX];
	ve_nha_may();
	xoacontro();
	khoi_tao_ran(toadox, toadoy);
	ve_ran(toadox, toadoy);
	// kiem tra va tao qua
	srand(time(NULL));
	int xqua = 0, yqua = 0;
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;
	int check = 2;
	while(gameover == false){
		xoa_dulieu_cu(toadox, toadoy);
		// dieu khien
		if(kbhit()){
			char kitu = getch();
			if(kitu == -32){
				kitu = getch();
				if(kitu == 72 && check != 0){
					check = 1;
				}
				else if(kitu == 80 && check != 1){
					check = 0;
				}
				else if(kitu == 77 && check != 3){
					check = 2;
				}
				else if(kitu == 75 && check != 2){
					check = 3;
				}
			}
		}
		if(check == 0){
			y++;// di xuong
		}
		else if(check == 1){
			y--;// di len
		}
		else if(check == 2){
			x++;// di qua phai
		}
		else if(check == 3){
			x--;// di qua trai
		}
		xu_ly_ran(toadox, toadoy, x, y, xqua, yqua);
		// kiem tra
	    if(gameover = kt_nha_may(toadox, toadoy)){
			SetColor(15);
			gotoXY(53, 12);
			printf("LOSE :((");
			gotoXY(50, 13);
			printf("Your score: %d", score);
			if(score>maxscore){
				maxscore = score;
				xuatVaoFile(maxscore);
			}	
			Sleep(1500);
			system("cls");
		}
		if (check == 1 || check == 0)
        	Sleep(100);
		else if (check == 2 || check == 3)
			Sleep(60);
	}
	    _getch();
	    return ;
}

void printWelcome()
{
	int i;
	while (true)
	{
		i = rand() % 15 + 1 + 1;
		if (i % 16 == 0)
			i = 1;
		SetColor(i);
		gotoXY(25, 1);
		printf("   _____             _         ");
		gotoXY(25, 2);
		printf("  / ____|           | |        ");
		gotoXY(25, 3);
		printf(" | (___  _ __   __ _| | _____  ");
		gotoXY(25, 4);
		printf("  \\___ \\| '_ \\ / _` | |/ / _ \\ ");
		gotoXY(25, 5);
		printf("  ____) | | | | (_| |   <  __/ ");
		gotoXY(25, 6);
		printf(" |_____/|_| |_|\\__,_|_|\\_\\___| ");

		gotoXY(35, 8);
		printf("\\ \\ / /             (_)       ");
		gotoXY(35, 9);
		printf(" \\ V / ___ _ __  _____  __ _  ");
		gotoXY(35, 10);
		printf("  > < / _ \\ '_ \\|_  / |/ _` | ");
		gotoXY(35, 11);
		printf(" / . \\  __/ | | |/ /| | (_| | ");
		gotoXY(35, 12);
		printf("/_/ \\_\\___|_| |_/___|_|\\__,_| ");
		gotoXY(35, 13);
		Sleep(500);
		if (_kbhit() == true)
		{
			char a = _getch();
			if (a == 13)
				break;
		}
	}
}

void printInfo()
{
	int x = 10, y = 22;
	int xcu = -1, ycu = -1;
	SetColor(11);
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		printf("                       ");
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		printf("Group: 20");
		y--;
		if (y == 14)
			break;
		Sleep(150);
	}
	x = 10, y = 22;
	xcu = -1, ycu = -1;
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		printf("                       ");
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		printf("Members: DANG NGOC MINH");
		y--;
		if (y == 15)
			break;
		Sleep(150);
	}
	x = 10, y = 22;
	xcu = -1, ycu = -1;
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		printf("                        ");
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		printf("NGUYEN VAN DIA LOI");
		y--;
		if (y == 16)
			break;
		Sleep(150);
	}
	x = 10, y = 22;
	xcu = -1, ycu = -1;
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		printf("                        ");
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		printf("LE TRUNG KHANG");
		y--;
		if (y == 17)
			break;
		Sleep(150);
	}
	x = 10, y = 22;
	xcu = -1, ycu = -1;
	while (true)
	{
		// xoa cu
		gotoXY(xcu, ycu);
		printf("                        ");
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		printf("NGUYEN NGUYEN HOANG ANH");
		y--;
		if (y == 18)
			break;
		Sleep(150);
	}
}

void printLoadingBar()
{
	SetColor(2);
	gotoXY(7, 25);
	printf("LOADING..");
	char x = 219;
	int r = 0;
	for (int i = 19; i <= 80; i++)
	{
		gotoXY(16, 25);
		printf(".");
		Sleep(80);
		gotoXY(16, 25);
		printf(" ");
		gotoXY(i, 25);
		if (i <= 44)
			Sleep(5);
		else
			Sleep(2);
		printf("%c", x);
		gotoXY(82, 25);
		if (i == 80)
		{
			cout << 100 << "%";
			gotoXY(16, 25);
			printf(".");
			break;
		}
		else
		{
			cout << r << "%";
			r++;
		}
	}
	//_getch();
	system("cls");
} 

void highlightMenu()
{
	int xmove = 44;
	int ymove = 9;
	char c; 
	while (true)
	{
		printf("                     ");
		gotoXY(44, 9);
		TextColor(15);
		printf("GAME MENU                         ");
		gotoXY(44, 10);
		TextColor(15);
		printf("TUTORIAL                     ");
		gotoXY(44, 11);
		TextColor(15);
		printf("                   ");
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == 72)
				ymove--;
			if (c == 80)
				ymove++;
			if (c == '\r')
			{
				if (ymove == 9)
				{
					menu_choice = 1;
					system("cls");
					che_do();
					break;
				}
				else if (ymove == 10)
				{
					menu_choice = 2;
					system("cls");
					HuongDan();
					
					break;
				}
			}
		}
		if (ymove < 9)
			ymove = 10;
		else if (ymove > 10)
			ymove = 9;
		if (ymove == 9)
		{
			gotoXY(44, 9);
			SetColor(4);
			printf("GAME MENU");
		}
		if (ymove == 10)
		{
			gotoXY(44, 10);
			SetColor(4);
			printf("TUTORIAL");
		}
		Sleep(100);
		ShowCur(0);
	}
}

void che_do(){
	int xmove = 44;
	int ymove = 9;
	char c; 
	while (true)
	{ 
		gotoXY(15, 28);
		printf("                     ");
		gotoXY(44, 9);
		TextColor(15);
		printf("CHOI THUONG  ");//     KINH DIEN
		gotoXY(44, 10);
		TextColor(15);
		printf("ME CUNG  ");//  CHIEN DICH
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == 72)
				ymove--;
			if (c == 80)
				ymove++;
			if(c == 27)
	          	highlightMenu();
			if (c == '\r')
			{
				if (ymove == 9)
				{
					menu_choice = 1;
					system("cls");
					score = 0;
					sl = 3;
					normal();
					if(c == 13) highlightMenu();
					break;
				}
				else if (ymove == 10)
				{
					menu_choice = 2;
					system("cls");
					map();
					//if(c == 13) highlightMenu();
					break;
				}
			}
		}
		if (ymove < 9)
			ymove = 10;
		else if (ymove > 10)
			ymove = 9;
		if (ymove == 9)
		{
			gotoXY(44, 9);
			SetColor(11);
			printf("CHOI THUONG  ");
		}
		if (ymove == 10)
		{
			gotoXY(44, 10);
			SetColor(11);
			printf("ME CUNG  ");
		}
		Sleep(100);
		ShowCur(0);
	}
}

void map()
{
	int xmove = 44;
	int ymove = 9;
	char c; 
	while(true)
	{
		gotoXY(18, 28);
		printf("                     ");
		gotoXY(44, 9);
		TextColor(15);
		printf("DUONG RAY");//  CHIEN DICH
		gotoXY(44, 10);
		TextColor(15);
		printf("NHA MAY");//     HIEN DAI
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == 72)
				ymove--;
			if (c == 80)
				ymove++;
			if(c == 27)
	          	che_do();
			if (c == '\r')
			{
				if (ymove == 9)
				{
					menu_choice = 1;
					system("cls");
					score = 0;
					sl = 3;
					DuongRay();
					if(c == 13) map();
					break;
				}
				else if (ymove == 10)
				{
					menu_choice = 2;
					system("cls");
					score = 0;
					sl = 3;
					NhaMay();
					if(c == 13) map();
				    break;
				}
			}
		}
		if (ymove < 9)
			ymove = 10;
		else if (ymove > 10)
			ymove = 9;
		if (ymove == 9)
		{
			gotoXY(44, 9);
			SetColor(11);
			printf("DUONG RAY");
		}
		if (ymove == 10)
		{
			gotoXY(44, 10);
			SetColor(11);
			printf("NHA MAY");
		}
		Sleep(100);
		ShowCur(0);
	} 
}

void HuongDan(){
	char c;
	SetColor(11);
	while (true)
	{
		gotoXY(44, 9);
	    printf("Su dung phim mui ten de di chuyen");
	    gotoXY(44, 10);
	    printf("Enter: xac nhan lua chon");
	    gotoXY(44, 11);
	    printf("ESC: quay lai");
		if(_kbhit() == true){
		c = _getch();
		if(c == 27) highlightMenu();
	   }
	}
}
