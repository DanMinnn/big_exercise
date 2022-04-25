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
int sl = 3, score = 0, maxscore = 0;
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
void xoacontro();

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
		printf("%c",196);
		gotoXY(i, ybot);
		printf("%c",196);
	}
	for (int i = ytop; i <= ybot; i++) //1
	{
		gotoXY(xleft, i);
		printf("%c",179);
		gotoXY(xright, i);
		printf("%c",179);
	}
	gotoXY(xleft, ytop); // 1 1
	printf("%c",218);
	gotoXY(xright, ytop); // 92 20
	printf("%c",191);
	gotoXY(xleft, ybot);  // 1 20
	printf("%c",192);
	gotoXY(xright, ybot); // 92 20
	printf("%c",217);
	SetColor(15);
}

void ve_tuong_duong_ray()
{
	ve_tuong(10, 100, 1, 26); // 1 92 1 21
	gotoXY(33, 7);
	for (int i = 33; i < 73; i++)
		printf("%c",15);
	gotoXY(33, 18);
	for (int i = 33; i < 73; i++)
		printf("%c",15);
}

void ve_nha_may(){
    ve_tuong(10, 100, 1, 26);
    for(int i = 10; i <= 13; i++){ //1
       gotoXY(45, i);
       printf("+");
    }
    for(int i = 5; i <= 8; i++){ //2
       gotoXY(20, i);
       printf("+");
    }
    for(int i = 15; i <= 18; i++){ //3
       gotoXY(80, i);
       printf("+");
    }
    for(int i = 20; i <= 30; i++){ //4
       gotoXY(i, 13);
       printf("+");
    }
    for(int i = 40; i <= 80; i++){ //5
       gotoXY(i, 5);
       printf("+");
    }
    for(int i = 15; i <= 71; i++){ //6
       gotoXY(i, 22);
       printf("+");
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
	    	printf("%c", 3);
			SetColor(4);
		}
		else printf("%c", 4);
	}
}

void xoa_dulieu_cu(int toadox[], int toadoy[]){
	for(int i = 0; i < sl; i++){
		gotoXY(toadox[i],toadoy[i]);
	    	printf(" ");
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
		SetColor(15);
		gotoXY(4, 0);
		cout << "Score: " << ++score;
		sl--;
	    tao_qua(xqua,yqua,toadox,toadoy);	
}
	// ve ran
	ve_ran(toadox, toadoy);
}

void xuatVaoFile(int score){
	FILE *f;
	f = fopen("E:/C-CPP/snake/Diem.txt", "w");
	fprintf(f,"Diem cao nhat: %d",score);
	fclose(f);
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
	    if(kt1 == true || kt2 == true)
			return true;
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
	    if(kt1 == true || kt2 == true)
	    	return true;// gameover
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
	printf("%c", 2);
	SetColor(7);
}

bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]){
	for(int i = 0; i < sl; i++){
		if((xqua == toadox[i]) && (yqua == toadoy[i]))
			return true;// ran de len qua
	}
	return false;
}

bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0){
	if((x0 == xqua) && (y0 == yqua))
	     return true;
	return false;
}

