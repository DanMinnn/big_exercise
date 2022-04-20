#include <iostream>
using namespace std;
#include <winbgim.h>
#include <string.h>
#include <stdio.h>
#include <time.h>
struct HighScore {
	int score;
	char name[30];
};
void showHighScore();
void getHighScore();
void checkHighScore(int score);
void initScore();
bool isEmpty();
HighScore  highscore[5];
char* score_str = new char[20];// Convert score to string
void initScore(){
		if (isEmpty()){
			for (int i = 0;i < 5;i++){
			strcpy(highscore[i].name,"PLAYER");
			highscore[i].score = 0;
			}
			getHighScore();
		}else{
			char arr[20];
			int count = 0;
			FILE *f;
			f = fopen("highscore.txt", "r");
			for (int i = 0;i < 5;){
				while (!feof(f)){
					count++;
					fscanf(f, "%s", arr);
				   if (count%2 == 1){
				   		strcpy(highscore[i].name,arr);
						//printf ("%s\t",ch);
					}
					else{
						highscore[i].score = atoi(arr);
						i++;
						}
				   }
				}
			}
}
bool isEmpty(){
	FILE *fp;
	long size;
	fp = fopen("highscore.txt","r");
	if(fp){
		fseek (fp, 0, SEEK_END);
        size = ftell(fp);
		fclose(fp);
	}
	return(size == 0);
}
void showHighScore(){
	FILE *f;
	f = fopen("highscore.txt", "r");
	char ch[20];
	settextstyle (1,0,5);
	setcolor (15);
	outtextxy (150,50,"HIGH SCORE");
	settextstyle (1,0,4);
	int y = 150,count = 0;
	while (!feof(f)){
		if (count == 10) break;
		count++;
		fscanf(f, "%s", ch);
   		if (count%2 == 1){
   			setcolor (10);
   			outtextxy (180,y,ch);
   			y+=50;
		}else{
			setcolor (12);
			outtextxy (500,y-50,ch);	   	
		}
	}
	fclose(f);
}
void getHighScore (){
	FILE *f;
	f = fopen("highscore.txt", "w");
	for (int i = 0;i < 5;i++){
		fputs(highscore[i].name,f);
		fputs(" ",f);
		fprintf(f,"%d",highscore[i].score);
		fputs("\n",f);
	}
	fclose(f);
}
void checkHighScore (int _score){
	char _name[20]={""};
	for (int i = 0;i < 5;i++){
		if (_score > highscore[i].score){
			//to do sth
			settextstyle(1,0,3);
				for (int j = 0;j < 50;j++){
					if (j%2 == 0){
						setcolor (14);
						if (i == 0)
						outtextxy(460,100,"BEST SCORE");
						else
						outtextxy(460,100,"HIGH SCORE");
						delay(100);
					}else{
						setcolor (9);
						if (i == 0)
						outtextxy(460,100,"BEST SCORE");
						else
						outtextxy(460,100,"HIGH SCORE");
						delay(100);
					}
				}
				settextstyle(1,0,2);
				setcolor (4);outtextxy(430,150,"Player:");
				delay(100);
				char ch1;
				int x = 0;
				char str[2];
				str[1] = 0;
				while (ch1 != 13 && x < 10){
					do{
						ch1 = getch();
					}while (ch1 < 65 && ch1 >90 || ch1 < 97 && ch1 > 132);
					x++;
					str[0] = ch1;
					strcat(_name,str);
					outtextxy(540,150,_name);
				}
			for (int j = 4;j > i;j--){
				strcpy(highscore[j].name,highscore[j-1].name);
				highscore[j].score = highscore[j-1].score;
			}
			strcpy(highscore[i].name,_name);
			highscore[i].score = _score;
			break;
		}
	}
	getHighScore();
}
