#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<string.h>
#include<time.h>
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	return coninfo.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO coninfo;
	GetConsoleScreenBufferInfo (GetStdHandle(STD_OUTPUT_HANDLE), &coninfo);
	return coninfo.dwCursorPosition.Y;
}
void gotoXY(int x, int y)
{
    static HANDLE  h = NULL;
    if(!h)
        h = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD c = {x,y};
    SetConsoleCursorPosition(h,c);
}
void SetTeColor(WORD color)
{ 
    HANDLE hConsoleOutput;
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO screen_buffer_info;
    GetConsoleScreenBufferInfo(hConsoleOutput, &screen_buffer_info);
    WORD wAttributes = screen_buffer_info.wAttributes;
    color &= 0x000f;
    wAttributes &= 0xfff0; wAttributes |= color;
    SetConsoleTextAttribute(hConsoleOutput, wAttributes);
}


void ve_tuong_tren(){
		int x=10,y=1;
		while(x<=100){
	     gotoXY(x,y);
		 printf("+");
		 x++;
		}		
}
void ve_tuong_duoi(){
	int x=10,y=26;
		while(x<=100){
	     gotoXY(x,y);
		 printf("+");
		 x++;
}
}
void ve_tuong_trai(){
	int x=10,y=1;
		while(y<=26){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void ve_tuong_phai(){
	int x=100,y=1;
		while(y<=26){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong1(){
	int x=45,y=10;
		while(y<=13){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong2(){
	int x=20,y=5;
		while(y<=8){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong3(){
	int x=80,y=15;
		while(y<=18){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong4(){
	int x=20,y=13;
		while(x<=30){
	     gotoXY(x,y);
		 printf("+");
		 x++;
}
}
void duong5(){
	int x=40,y=5;
		while(x<=80){
	     gotoXY(x,y);
		 printf("+");
		 x++;
}
}
void duong6(){
	int x=15,y=22;
		while(x<=71){
	     gotoXY(x,y);
		 printf("+");
		 x++;
}
}
int main(){
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	duong1();
	duong2();
	duong3();
	duong4();
	duong5();
	duong6();
}

	
	
	
	

