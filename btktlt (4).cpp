// toa do x(0;28) y(0;100)
#include <iostream>
#include "mylib.h"
#define MAX 100
using namespace std;
int sl = 3;
void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int &xqua, int &yqua)
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
void tao_qua(int &xqua, int &yqua, int toadox[], int toadoy[]);
bool kt_ran_de_qua(int xqua, int yqua, int toadox[], int toadoy[]);
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0);


int main();
{
	int toadox[MAX], toadoy[MAX];
	srand(time(NULL));
	int xqua, yqua;
	//taoqua
	tao_qua(xqua, yqua, toadox, toadoy);
	int x = 50, y = 13;// vitri dau
	int check = 0;
	while (true)
	{//kiemtrahuong
	 // 0 cham vao bien tren di xuong 
	// 1 cham vao bien duoi di len 
	// 2 cham vao vien phai di qua trai
	// 3 cham vao bien trai di qua phai
		
		if (check == 0)
		{
			y++; //di xuong
		}
		else if (check == 1)
		{
			y--; // di len
		}
		else if (check == 2)
		{
			x--; // qua trai
		}
		else if (check == 3)
		{
			x++; // qua phai
		}
		xu_ly_ran(toadox, toadoy, x, y);
		sleep(300);

	}
	_getch();
	//dieukhien
	if (_kbhit())
	{
		char kitu = _getch();
		if (kitu == -32)
		{
			kitu = _getch();
			if (kitu == 72)// di len 
			{
				check = 1;

			}
			else if (kitu == 80) // di xuong 
			{
				check = 0;
			}
			else if (kitu == 75) //di trai
			{
				check = 2;
			}
			else if (kitu == 77) // di phai
			{
				check = 3;
			}
		}

	}
	
	return 0;
}
	
	void xu_ly_ran(int toadox[], int toadoy[], int x, int y, int& xqua, int& yqua)
	{//them toa do moi vao dau mang
		them(toadox, x);
		them(toadoy, y);

		if (kt_ran_an_qua(xqua, yqua, toadox[0], toadoy[0]) == false)
		{
			//b2 xoa toa do cuoi mang
			xoa(toadox, sl - 1);
			xoa(toadoy, sl - 1);

		}
		else
		{
			tao_qua(xqua, yqua, toadox, toadoy);
		}


		//b3 ve ran
		ve_ran(toadox, toadoy);
	}
	while (true)
	

void tao_qua(int &xqua,int &yqua, int toadox[], int toadoy[]) //random
{
   do
	{
		//11<x<99
		xqua = rand() % (99 - 11 + 1) + 11;
		//2<y25
		yqua = rand() % (25 - 2 + 1) + 2;
	} while (kt_ran_de_qua(xqua, yqua, toadox, toadoy) == true);
	gotoXY(xqua, yqua);
	cout << "o"
}
bool kt_ran_de_qua(int xqua, int yqua, int toadox[],int toadoy[])
{
	for (int i = 0; i < sl; i++)
	{
		if ((xqua == toadox[i])&&(yqua == toadoy[i]))
		{
			return true; // ran de len qua 
		}
	}
	return false;
}
bool kt_ran_an_qua(int xqua, int yqua, int x0, int y0)
{
	if ((x0 == xqua) && (y0 == yqua))
	{
		return true; // ran an qua
	}
	return false;
}