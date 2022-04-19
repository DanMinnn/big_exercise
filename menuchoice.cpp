#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string.h>
#include "mylib.h"
using namespace std;

int menu_choice;
int menuchoice;
#define MAX 100
using namespace std;
int sl = 3;
int opt,x,y;
void ve_tuong(int xleft, int xright, int ytop, int ybot);
void ve_tuong_duong_ray();
void ve_nha_may();
void khoi_tao_ran(int toadox[], int toadoy[]);
void xoa_dulieu_cu(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void level();
void che_do();
void map();
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
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);
void xoacontro();

void printWelcome();
void printInfo();
void printLoadingBar();
void highlightMenu();

void xoacontro()
{
 CONSOLE_CURSOR_INFO Info;
 Info.bVisible = FALSE;
 Info.dwSize = 20;
 SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}

void ve_tuong(int xleft, int xright, int ytop, int ybot)
{
	SetColor(10);
	for (int i = xleft; i <= xright; i++)  //1
	{
		gotoXY(i,ytop);
		cout << char(196);
		gotoXY(i, ybot);
		cout << char(196);
	}
	for (int i = ytop; i <= ybot; i++) //1
	{
		gotoXY(xleft, i);
		cout << char(179);
		gotoXY(xright, i);
		cout << char(179);
	}
	gotoXY(xleft, ytop); // 1 1
	cout << char(218);
	gotoXY(xright, ytop); // 92 20
	cout << char(191);
	gotoXY(xleft, ybot);  // 1 20
	cout << char(192);
	gotoXY(xright, ybot); // 92 20
	cout << char(217);
	SetColor(15);
}

void ve_tuong_duong_ray()
{
	ve_tuong(10, 100, 1, 26); // 1 92 1 21
	gotoXY(33, 7);
	for (int i = 33; i < 73; i++)
	{
		cout << "-";
	}
	gotoXY(33, 18);
	for (int i = 33; i < 73; i++)
	{
		cout << "-";
	}
}

void ve_nha_may(){
    ve_tuong(10, 100, 1, 26);
    for(int i = 10; i <= 13; i++){ //1
       gotoXY(45, i);
       cout << "+";
    }
    for(int i = 5; i <= 8; i++){ //2
       gotoXY(20, i);
       cout << "+";
    }
    for(int i = 15; i <= 18; i++){ //3
       gotoXY(80, i);
       cout << "+";
    }
    for(int i = 20; i <= 30; i++){ //4
       gotoXY(i, 13);
       cout << "+";
    }
    for(int i = 40; i <= 80; i++){ //5
       gotoXY(i, 5);
       cout << "+";
    }
    for(int i = 15; i <= 71; i++){ //6
       gotoXY(i, 22);
       cout << "+";
    }
}

void khoi_tao_ran(int toadox[], int toadoy[]){
	int x = 50, y = 13;
	for(int i = 0; i < sl;i++){
		toadox[i] = x;
		toadoy[i] = y;
		x--;
	}
}

void ve_ran(int toadox[], int toadoy[]){
	SetColor(2);
	for(int i = 0; i < sl; i++){
		gotoXY(toadox[i],toadoy[i]);
	    if(i == 0){
	    	cout << char(3);
		}
		else cout << char(4);
	}
}

void xoa_dulieu_cu(int toadox[], int toadoy[]){
	for(int i = 0; i < sl; i++){
		gotoXY(toadox[i],toadoy[i]);
	    	cout << " ";
	}
}

void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua){
	// them toa do moi vao dau mang
	them(toadox, x);
	them(toadoy, y);
	if(kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false){
		// xoa toa do cuoi mang
		xoa(toadox, sl - 1);
	    xoa(toadoy, sl - 1);
	}
	else {
		sl--;
	     tao_qua(xqua,yqua,toadox,toadoy);	
	}
	// ve ran
	ve_ran(toadox, toadoy);
}

void them(int a[], int x){
	for(int i = sl; i > 0; i--){
		a[i] = a[i - 1];
	}
	a[0] = x;
	sl++;
}

void xoa(int a[], int vt){
	for(int i = vt; i < sl; i++){
		a[i] = a[i + 1];
	}
	sl--;
}
   
bool kt_ran_cham_tuong(int x0, int y0){
	// ran cham tuong tren
	if(y0 == 1 && (x0 >= 10 && x0 <= 100)){
		return true;
	}
	// ran cham tuong duoi
	else if(y0 == 26 && (x0 >= 10 && x0 <= 100))
	    return true;
	else if(x0 == 100 && (y0 >= 1 && y0 <= 26))
	    return true;
	else if(x0 == 10 && (y0 >= 1 && y0 <= 26))
	    return true;
	return false;
}

bool kt_ran_duong_ray(int x0, int y0){
	// ran cham tuong tren
	if(y0 == 1 && (x0 >= 10 && x0 <= 100)){
		return true;
	}
	if(y0 == 7 && (x0 >= 33 && x0 <= 73))
		return true;
	// ran cham tuong duoi
	else if(y0 == 26 && (x0 >= 10 && x0 <= 100))
	    return true;
	else if(y0 == 18 && (x0 >= 33 && x0 <= 73))
		return true;
	else if(x0 == 100 && (y0 >= 1 && y0 <= 26))
	    return true;
	else if(x0 == 10 && (y0 >= 1 && y0 <= 26))
	    return true;
	return false;
}

bool kt_ran_nha_may(int x0, int y0){
	// ran cham tuong tren
	if(y0 == 1 && (x0 >= 10 && x0 <= 100))
		return true;
	if(x0 == 45 && (y0 >= 10 && y0 <= 13))
		return true;
	else if(x0 == 20 && (y0 >= 5 && y0 <= 8))
		return true;
	else if(x0 == 80 && (y0 >= 15 && y0 <= 18))
		return true;
	// ran cham tuong duoi
	else if(y0 == 26 && (x0 >= 10 && x0 <= 100))
	    return true;
	else if(y0 == 13 && (x0 >= 20 && x0 <= 30))
		return true;
	else if(y0 == 5 && (x0 >= 40 && x0 <= 80))
		return true;
	else if(y0 == 22 && (x0 >= 15 && x0 <= 71))
		return true;
	else if(x0 == 100 && (y0 >= 1 && y0 <= 26))
	    return true;
	else if(x0 == 10 && (y0 >= 1 && y0 <= 26))
	    return true;
	// ran cham duong ham
	return false;
	
}

bool kt_ran_cham_duoi(int toadox[], int toadoy[]){
	for(int i = 1; i < sl; i++){
		if((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		      return true;
	}
	return false;
}

bool kt_ran(int toadox[], int toadoy[]){
	    bool kt1 = kt_ran_cham_duoi(toadox, toadoy);
	    bool kt2 = kt_ran_cham_tuong(toadox[0], toadoy[0]);
	    if(kt1 == true || kt2 == true){
			return true;
		}
		return false;

}

bool kt_duong_ray(int toadox[], int toadoy[]){
	    bool kt1 = kt_ran_cham_duoi(toadox, toadoy);
	    bool kt2 = kt_ran_duong_ray(toadox[0], toadoy[0]);
	    if(kt1 == true || kt2 == true){
	    	return true;// gameover
		}
		return false;
}

bool kt_nha_may(int toadox[], int toadoy[]){
	    bool kt1 = kt_ran_cham_duoi(toadox, toadoy);
	    bool kt2 = kt_ran_nha_may(toadox[0], toadoy[0]);
	    if(kt1 == true || kt2 == true){
	    	return true;// gameover
		}
		return false;
}

void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]){
	do{
		 // 11 <=  xqua <= 99
	     xqua = rand() % (99 - 11 + 1) + 11;
     	// 2 <= yqua <= 25
	     yqua = rand() % (25 - 2 + 1) + 2;
	}while(kt_ran_de_qua(xqua, yqua, toadox, toadoy) ==  true);
	int i = rand() % (15 - 1 + 1) + 1;
	SetColor(i);
	gotoXY(xqua, yqua);
	cout << char(2);
	SetColor(7);
}

bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]){
	for(int i = 0; i < sl; i++){
		if((xqua == toadox[i]) && (yqua == toadoy[i])){
			return true;// ran de len qua
		}
	}
	return false;
}

bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0){
	if((x0 == xqua) && (y0 == yqua))
	     return true;
	return false;
}

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
		//system("cls");
		//backspace
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
	    if(gameover = kt_ran(toadox, toadoy)){
			ve_tuong(46, 61, 10, 14);// 10 100 1 26 // 38, 53, 9, 13
			gotoXY(50, 12);
			cout << "LOSE :((";
			Sleep(1500);
			system("cls");
		}
		if (check == 1 || check == 0)
        	Sleep(100);
		else if (check == 2 || check == 3)
			Sleep(60);
		gotoXY(15, 28);
	    printf("%c/%c/%c/%c: Di chuyen \t Enter: Quay lai menu ",16,17,30,31);
	}
	gameover == true;
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
		//system("cls");
		//backspace
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
			ve_tuong(46, 61, 10, 14);// 10 100 1 26 // 38, 53, 9, 13
			gotoXY(50, 12);
			cout << "LOSE :((";
			Sleep(1500);
			system("cls");
		}
		if (check == 1 || check == 0)
        	Sleep(100);
		else if (check == 2 || check == 3)
			Sleep(60);
		gotoXY(15, 28);
	    printf("%c/%c/%c/%c: Di chuyen \t Enter: Quay lai menu ",16,17,30,31);
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
		//system("cls");
		//backspace
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
			ve_tuong(46, 61, 10, 14);// 10 100 1 26 // 38, 53, 9, 13
			gotoXY(50, 12);
			cout << "LOSE :((";
			Sleep(1500);
			system("cls");
		}
		if (check == 1 || check == 0)
        	Sleep(100);
		else if (check == 2 || check == 3)
			Sleep(60);
		gotoXY(15, 28);
	    printf("%c/%c/%c/%c: Di chuyen \t Enter: Quay lai menu ",16,17,30,31);
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
		cout << "   _____             _         ";
		gotoXY(25, 2);
		cout << "  / ____|           | |        ";
		gotoXY(25, 3);
		cout << " | (___  _ __   __ _| | _____  ";
		gotoXY(25, 4);
		cout << "  \\___ \\| '_ \\ / _` | |/ / _ \\ ";
		gotoXY(25, 5);
		cout << "  ____) | | | | (_| |   <  __/ ";
		gotoXY(25, 6);
		cout << " |_____/|_| |_|\\__,_|_|\\_\\___| ";

		gotoXY(35, 8);
		cout << "\\ \\ / /             (_)       ";
		gotoXY(35, 9);
		cout << " \\ V / ___ _ __  _____  __ _  ";
		gotoXY(35, 10);
		cout << "  > < / _ \\ '_ \\|_  / |/ _` | ";
		gotoXY(35, 11);
		cout << " / . \\  __/ | | |/ /| | (_| | ";
		gotoXY(35, 12);
		cout << "/_/ \\_\\___|_| |_/___|_|\\__,_| ";
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
		cout << "                       ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "Group: 20";
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
		cout << "                        ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "Members: DANG NGOC MINH";
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
		cout << "                        ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "NGUYEN VAN DIA LOI";
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
		cout << "                        ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "LE TRUNG KHANG";
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
		cout << "                        ";
		xcu = x;
		ycu = y;
		gotoXY(x, y);
		cout << "NGUYEN NGUYEN HOANG ANH";
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
	cout << "LOADING..";
	char x = 219;
	int r = 0;
	for (int i = 19; i <= 80; i++)
	{
		gotoXY(16, 25);
		cout << ".";
		Sleep(80);
		gotoXY(16, 25);
		cout << " ";
		gotoXY(i, 25);
		if (i <= 44)
		{
			Sleep(5);
		}
		else
		{
			Sleep(2);
		}
		cout << x;
		gotoXY(82, 25);
		if (i == 80)
		{
			cout << 100 << "%";
			gotoXY(16, 25);
			cout << ".";
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
	
	int check = 0;
	while (true)
	{
		gotoXY(44, 9);
		TextColor(15);
		cout << "GAME MENU       ";//     KINH DIEN
		gotoXY(44, 10);
		TextColor(15);
		cout << "LEVEL      ";//  CHIEN DICH
		gotoXY(44, 11);
		TextColor(15);
		cout << "HIGH SCORE ";//     HIEN DAI
		gotoXY(44, 12);
		TextColor(15);
		cout << "EXIT       ";
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == 72)
			{
				ymove--;
			}
			if (c == 80)
			{
				ymove++;
			}
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
					level();
					break;
				}
				else if (ymove == 11)
				{
					menu_choice = 3;
					system("cls");
				    break;
				}
				else if (ymove == 12)
				{
					break;
				}
			}
		}
		if (ymove < 9)
			ymove = 12;
		else if (ymove > 12)
			ymove = 9;
		if (ymove == 9)
		{
			gotoXY(44, 9);
			SetColor(4);
			cout << "GAME MENU       ";
		}
		if (ymove == 10)
		{
			gotoXY(44, 10);
			SetColor(4);
			cout << "LEVEL      ";
		}
		if (ymove == 11)
		{
			gotoXY(44, 11);
			SetColor(4);
			cout << "HIGH SCORE ";
		}
		if (ymove == 12)
		{
			gotoXY(44, 12);
			SetColor(4);
			cout << "EXIT ";
		}
		gotoXY(18, 28);
		printf("%c/%c: Thay doi tuy chon                     \t Enter: Xac nhan               ",30,31);
		Sleep(100);
		ShowCur(0);
	}
}

void level(){
	char c;
	int x = 10, y = 15;
    gotoXY(10, 15);
	TextColor(2);
	cout << "LEVEL: ";
	while (true){
	    gotoXY(30, 15);
		TextColor(15);
	    cout << "1";
	    gotoXY(35, 15);
		TextColor(15);
	    cout << "2";
	    gotoXY(40, 15);
		TextColor(15);
	    cout << "3";
	    gotoXY(45, 15);
		TextColor(15);
	    cout << "4";
	    gotoXY(50, 15);
		TextColor(15);
	    cout << "5";
		if(_kbhit() == true){
			c = _getch();
			if(c == 75){
				x-=5;
			}
			if(c == 77){
				x+=5;
			}
			if(c == '\r'){
				if(x == 30){
					menuchoice = 1;
					system("cls");
					break;
				}
				else if(x == 35){
					menuchoice = 2;
					system("cls");
					Sleep(210);
					break;
				}
				else if(x == 40){
					menuchoice = 3;
					system("cls");
					Sleep(170);
					break;
				}
				else if(x == 45){
					menuchoice = 4;
					system("cls");
					Sleep(130);
					break;
				}
				else if(x == 50){
					menuchoice = 5;
					system("cls");
					Sleep(110);
					break;
				}

			}
		}
		if(x > 50)
		   x = 30;
		else if(x < 30)
		    x = 50;
		if(x == 30){
			gotoXY(30, 15);
			SetColor(11);
			cout << "1";
		}
		if(x == 35){
			gotoXY(35,15);
			SetColor(11);
			cout << "2";
		}
		if(x == 40){
			gotoXY(40,15);
			SetColor(11);
			cout << "3";
		}
		if(x == 45){
			gotoXY(45,15);
			SetColor(11);
			cout << "4";
		}
		if(x == 50){
			gotoXY(50,15);
			SetColor(11);
			cout << "5";
		}
		Sleep(100);
		ShowCur(0);
	}
}

void che_do(){
	int xmove = 44;
	int ymove = 9;
	char c; 
	
	int check = 0;
	while (true)
	{
		gotoXY(44, 9);
		TextColor(15);
		cout << "CHOI THUONG  ";//     KINH DIEN
		gotoXY(44, 10);
		TextColor(15);
		cout << "ME CUNG  ";//  CHIEN DICH
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == 72)
			{
				ymove--;
			}
			if (c == 80)
			{
				ymove++;
			}
			if(c == 27)
	          	highlightMenu();
			if (c == '\r')
			{
				if (ymove == 9)
				{
					menu_choice = 1;
					system("cls");
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
			cout << "CHOI THUONG";
		}
		if (ymove == 10)
		{
			gotoXY(44, 10);
			SetColor(11);
			cout << "ME CUNG";
		}
		gotoXY(15, 28);
		printf("%c/%c: Thay doi tuy chon \t   Enter: Xac nhan \t ESC: Quay lai menu",30,31);
		Sleep(100);
		ShowCur(0);
	}
}

void map()
{
	int xmove = 44;
	int ymove = 9;
	char c; 
	
	while (true)
	{
		gotoXY(44, 10);
		TextColor(15);
		cout << "DUONG RAY       ";//  CHIEN DICH
		gotoXY(44, 11);
		TextColor(15);
		cout << "NHA MAY       ";//     HIEN DAI
		if (_kbhit() == true)
		{
			c = _getch();
			if (c == 72)
			{
				ymove--;
			}
			if (c == 80)
			{
				ymove++;
			}
			if(c == 27)
	          	che_do();
			if (c == '\r')
			{
				if (ymove == 10)
				{
					menu_choice = 1;
					system("cls");
					DuongRay();
					if(c == 13) map();
					break;
				}
				else if (ymove == 11)
				{
					menu_choice = 2;
					system("cls");
					NhaMay();
					if(c == 13) map();
				    break;
				}
			}
		}
		if (ymove < 10)
			ymove = 11;
		else if (ymove > 11)
			ymove = 10;
		if (ymove == 10)
		{
			gotoXY(44, 10);
			SetColor(11);
			cout << "DUONG RAY        ";
		}
		if (ymove == 11)
		{
			gotoXY(44, 11);
			SetColor(11);
			cout << "NHA MAY  ";
		}
		gotoXY(18, 28);
		printf("%c/%c: Thay doi tuy chon                 \t Enter: Xac nhan \t ESC: Quay lai che do",30,31);
		Sleep(100);
		ShowCur(0);
	} 
}

int main(){
    //printWelcome();
    //printInfo();
    //printLoadingBar();
    highlightMenu();
    getch();
}
