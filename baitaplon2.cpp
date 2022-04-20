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
void duong1a(){
	int x=45,y=1;
		while(y<=10){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong1b(){
	int x=45,y=13;
		while(y<=26){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong2a(){
	int x=65,y=1;
		while(y<=18){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong2b(){
	int x=65,y=21;
		while(y<=26){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong3a(){
	int x=28,y=1;
		while(y<=5){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong3b(){
	int x=28,y=8;
		while(y<=26){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong4a(){
	int x=83,y=1;
		while(y<=13){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
void duong4b(){
	int x=83,y=16;
		while(y<=26){
	     gotoXY(x,y);
		 printf("+");
		 y++;
}
}
int main(){
	ve_tuong_tren();
	ve_tuong_duoi();
	ve_tuong_trai();
	ve_tuong_phai();
	duong1a();
	duong1b();
	duong2a();
	duong2b();
	duong3a();
	duong3b();
	duong4a();
	duong4b();
}
