#include <iostream>
#include "lib.h"
#define MAX 100
void tuongtren();
void tuongduoi();
void tuongtrai();
void tuongphai();
void vetuong();
int sl=8;
void khoitaoran(int toadox[], int toadoy[]);
void ve_ran(int toadox[], int toadoy[]);
void xoa_du_lieu_cu(int toadox[], int toadoy[]);
void xu_ly_ran(int toadox[], int toadoy[],int x, int y);
void them(int a[],int x);
void xoa(int a[],int vt);
bool kt_ran_cham_tuong(int x0, int y0);
bool ran_cham_duoi(int toadox[],int toadoy[]);
bool kt_ran(int toadox[], int toadoy[]);
//---------------
void tuongtren(){
	int x = 10,y = 1;
	while(x	<= 100){
	gotoXY(x,y);
	printf("_");
	x++;
}
}
void tuongduoi(){
	int x = 10,y = 26;
	while(x	<= 100){
	gotoXY(x,y);
	printf("_");
	x++;
}
}
void tuongtrai(){
	int x = 10,y = 2;
	while(y	<= 26){
	gotoXY(x,y);
	printf("|");
	y++;
}
}
void tuongphai(){
	int x = 100,y = 2;
	while(y	<= 26){
	gotoXY(x,y);
	printf("|");
	y++;
}
}
void vetuong(){
	tuongtren();
	tuongduoi();
	tuongtrai();
	tuongphai();
}
//-------------
void khoitaoran(int toadox[], int toadoy[]){
	int x=50,y=13;
	for(int i = 0;i < sl;i++){
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
	    	printf("%c",3);
		}
		else printf("%c",4);
	}
}
void xoa_du_lieu_cu(int toadox[], int toadoy[]){
	SetColor(2);
	for(int i = 0; i < sl; i++){
		gotoXY(toadox[i],toadoy[i]);
		printf(" ");
	}
}
//---------------
void xu_ly_ran(int toadox[], int toadoy[],int x, int y){
	them(toadox,x);
	them(toadoy,y);
	xoa(toadox,sl-1);
	xoa(toadoy,sl-1);
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

bool kt_ran_cham_duoi(int toadox[], int toadoy[]){
	for(int i = 1; i < sl; i++){
		if((toadox[0] == toadox[i]) && (toadoy[0] == toadoy[i]))
		      return true;
	}
	return false;
}
bool kt_ran(int toadox[], int toadoy[]){
	bool kt1 = kt_ran_cham_duoi(toadox,toadoy);
	bool kt2 = kt_ran_cham_tuong(toadox[0],toadoy[0]);
	if (kt1 == true || kt2 == true){
			return true;
	}
	return false;
}
int main()
{
	bool gameover = false;
	int toadox[MAX],toadoy[MAX];
	vetuong();
	khoitaoran(toadox,toadoy);
	ve_ran(toadox,toadoy);	
	int x=50,y=13;
	int check = 2;
	while(gameover == false){
		xoa_du_lieu_cu(toadox, toadoy);
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
		xu_ly_ran(toadox, toadoy, x, y);
		// kiem tra
		gameover = kt_ran(toadox,toadoy);
		Sleep(100);
	}
	getch();
	return 0;
}

