#include <stdio.h>         
#include <stdlib.h>
#include <conio.h>   //箭頭的標頭檔
#include <time.h>
#include <windows.h>//Sleep需要的函式

int sum[4][4];	                                  //4*4的格子中所含的數字 
int num[4][4];	                                         //檢查是否有移動 
int check;	            //檢查是否有抓到方向，以解決主程式迴圈跑兩次的問題 
int checking = 0;	                                 //檢查是否還可以移動 
int over;
int temp[8] = { 2,2,2,2,2,2,2,4 };	                                //7:1陣列 
char ch;	                                                   //抓方向用 
char replay;	                                               //是否重玩 
int max = 0;	                                                 //最高分 
int score = 0;                                                     //分數 
int hard;	                                                   //遊戲難度 
void start()
{
	int i, j, k = 0;
	printf("\n\n\n\n\n\n歡迎來到2048!");
	printf("\n\n\n 請選擇遊戲難度(每次移動生成幾個數)\n");
	printf("\n建議 1 或 2 (不可大於5) : ");
	scanf("%d", &hard);
	while (hard > 5)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n歡迎來到2048!");
		printf("\n\n\n太難了!!!!!!!!!!\n");
		printf("\n\n 請重新輸入(不可大於5) : ");
		scanf("%d", &hard);
	}
	if (hard > 2)
		printf("\n大於2可能倒置遊戲難度過大!請做好準備!\n\n");
	Sleep(800);
	printf("\n\n 組員:");
	Sleep(1000);
	printf("謝坤霖\n      黃俊翰\n      蕭宗賓\n");
	Sleep(3000);
	system("cls");
	for (j = 1; 3 >= j; j++)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n ");
		Sleep(400);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n    遊戲開始!");
		Sleep(650);
	}
	Sleep(500);
}
void restart()                                    //重新開始時的輸入畫面
{
	system("cls");
	printf("\n\n\n\n\n\n\n請選擇遊戲難度(每次移動生成幾個數)\n");
	printf("\n\n建議 1 或 2 (不可大於5) : ");
	scanf("%d", &hard);
	while (hard > 5)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n太難了!!!(不可大於5)!!!!!!!\n");
		printf("\n\n      請重新輸入 : ");
		scanf("%d", &hard);
	}
	if (hard > 2)
		printf("\n\n 大於2可能倒置遊戲難度過大!請做好準備!\n\n");
	Sleep(1000);
	system("cls");
}
void bye()
{
	int i, j, k;
	for (i = 1; 8 >= i; i++)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n");
		printf("                                ");
		printf("BYE!!!BYE!!!");
		Sleep(100);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                             ");
		printf("BYE!!!BYE!!!");
		Sleep(100);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("                                                            ");
		printf("BYE!!!BYE!!!");
		Sleep(100);
		system("cls");
	}
}
void putin() {
	srand(time(NULL));
	int i, j;	                                       //用亂數選擇的座標
	int k;	                   //決定填入2或4 /*7:1的概率填入2或4*/                                        
	while (1)	                         /*座標為0時才會填入數字並跳出*/
	{
		i = rand() % 4;
		j = rand() % 4;
		k = rand() % 8;
		if (temp[k] == 2 && sum[i][j] == 0)
		{
			sum[i][j] = 2;
			break;
		}
		if (temp[k] == 4 && sum[i][j] == 0)
		{
			sum[i][j] = 4;
			break;
		}
	}
}

void square()
{
	system("cls");	                    /*清空畫面，讓新的畫面能覆蓋舊的*/
	int i, j;	                                                 //迴圈用
	int k = 0;
	printf("\n\n\n  最高紀錄:%d   當前分數:%d\n", max, score);
	/*印出4*4格子*/
	printf("\n\n----------------------------\n");
	for (i = 0; i < 4; i++) {
		printf("|");
		for (j = 0; j < 4; j++)
		{
			if (sum[i][j] == 0)	                /*如果座標為0時不印數字*/
				printf("     | ");
			else
				printf("%4d | ", sum[i][j]);
		}
		printf("\n----------------------------\n");
	}
	printf("\n  重新開始請按空白鍵\n");
	for (i = 0; 4 > i; i++)
		for (j = 0; 4 > j; j++)
		{
			if (sum[i][j] > 0)
				k++;
		}
	if (k >= 16)
	{
		printf("\n\n加油啊!肉雞!");
	}
	printf("\n\n\n組員:謝坤霖");
	printf("\n黃俊翰");
	printf("\n蕭宗賓");
}
void copy()
{
	int i, j, k;	                                          //座標 / 迴圈用
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			num[i][j] = sum[i][j];
}
void lave() {	                 //若剩餘的空個數小於預設生成數可繼續生成 
	int i, j;
	over = 0;
	for (j = 0; 4 > j; j++)
		for (i = 0; 4 > i; i++)
			if (sum[i][j] == 0)
				over++;

}
void move() {
	int i, j, k;	                                          //座標 / 迴圈用 
	int temp;                                               //暫存數字 

	if (ch == 75)	                                  /*往左移動(小座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j] == 0 && sum[i][j + 1] > 0) {
						temp = sum[i][j];
						sum[i][j] = sum[i][j + 1];
						sum[i][j + 1] = temp;
					}
	if (ch == 77)	                                  /*往右移動(大座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j + 1] == 0 && sum[i][j] > 0) {
						temp = sum[i][j + 1];
						sum[i][j + 1] = sum[i][j];
						sum[i][j] = temp;
					}
	if (ch == 72)	                                  /*往上移動(小座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j][i] == 0 && sum[j + 1][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	if (ch == 80)	                                 /*往下移動(大座標)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j + 1][i] == 0 && sum[j][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	for (i = 0; i < 4; i++)	                                   /*尋找最大數*/
		for (j = 0; j < 4; j++)
			if (score > max)
				max = score;
}



/*
	鍵盤(上) 72
	鍵盤(下) 80
	鍵盤(左) 75
	鍵盤(右) 77

座標(sum[i][j]):
	00	01	02	03
	10	11	12	13
	20	21	22	23
	30	31	32	33
*/
void plus() {
	int i, j;	                                                   //座標 
	if (ch == 75)	                                  /*往左移動(小座標)*/
		for (i = 0; i < 4; i++)
			for (j = 0; j < 3; j++)
				if (sum[i][j] == sum[i][j + 1]) {
					sum[i][j] += sum[i][j + 1];
					sum[i][j + 1] = 0;
					score += sum[i][j];
				}
	if (ch == 77)	                                  /*往右移動(大座標)*/
		for (i = 0; i < 4; i++)
			for (j = 3; j >= 0; j--)
				if (sum[i][j] == sum[i][j - 1]) {
					sum[i][j] += sum[i][j - 1];
					sum[i][j - 1] = 0;
					score += sum[i][j];
				}
	if (ch == 72)	                                  /*往上移動(小座標)*/
		for (i = 0; i < 4; i++)
			for (j = 0; j < 3; j++)
				if (sum[j][i] == sum[j + 1][i]) {
					sum[j][i] += sum[j + 1][i];
					sum[j + 1][i] = 0;
					score += sum[j][i];
				}
	if (ch == 80)	                                  /*往下移動(大座標)*/
		for (i = 0; i < 4; i++)
			for (j = 3; j >= 0; j--)
				if (sum[j][i] == sum[j - 1][i]) {
					sum[j][i] += sum[j - 1][i];
					sum[j - 1][i] = 0;
					score += sum[j][i];
				}
}
int point() {
	int i, j;	                                                   //座標 

	for (i = 0; i < 4; i++)	                                  /*尋找是否有0*/
		for (j = 0; j < 4; j++)
			if (sum[i][j] == 0)
				checking++;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			if (sum[i][j] == sum[i][j + 1])
				checking++;
	for (i = 0; i < 4; i++)
		for (j = 3; j >= 0; j--)
			if (sum[i][j] == sum[i][j - 1])
				checking++;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 3; j++)
			if (sum[j][i] == sum[j + 1][i])
				checking++;
	for (i = 0; i < 4; i++)
		for (j = 3; j >= 0; j--)
			if (sum[j][i] == sum[j - 1][i])
				checking++;
	if (checking == 0) {
		int i, j;	                                               //座標 
		printf("\n\n                                                    YOU LOSE!!!");
		Sleep(3000);
		system("cls");
		printf(" \n\n\n                                                  遊戲結束\n\n\n\n");
		printf("  當局分數:%d   最高分:%d\n\n\n\n", score, max);
		printf("是否重新開始(Y/N) ? ");
		scanf(" %c", &replay);
		if (replay == 'Y') {
			for (i = 0; i < 4; i++)	                             /*清空數字*/
				for (j = 0; j < 4; j++)
					sum[i][j] = 0;
		}
		if (replay == 'N') {
			bye();
			return 0;
		}
	}
}
void reset() {
	int i, j;
	score = 0;
	for (i = 0; i < 4; i++)	                                     /*清空數字*/
		for (j = 0; j < 4; j++)
			sum[i][j] = 0;
}
int main(int argc, char* argv[]) {
	start();
	int i, j;	                                          //座標 / 迴圈用
	int k = 0;	                                                 //檢查用 
	/*放入0(空白)*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			sum[i][j] = 0;
	}
	putin();	                                     /*開局時有兩個數字*/
	putin();
	square();
	while (1) {
		check = 0;	                       /*先歸0，有抓到方向才加1*/
		ch = getch(); 	/*抓方向*/
		if (ch == 72 || ch == 75 || ch == 77 || ch == 80) { check = 1; }		 /*偵測到方*/
		copy();		                           /*複製數字後面檢查用*/
		move();		                                    /*移動數字*/
		plus();		                                /*相鄰數字相加*/
		move();		                           /*相加完後再移動一次*/
		if (check != 0) {	                              /*有方向才會繼續*/
			square();	                 /*先印出移動完，還沒putin的畫面*/
			for (i = 0; i < 4; i++)	                       /*檢查是否有移動*/
				for (j = 0; j < 4; j++)
					if (num[i][j] == sum[i][j])
						k++;
			Sleep(200);
			if (k != 16) {	                             /*有移動才putin*/
				lave();

				if (over < hard)
					for (j = 1; over >= j; j++)
						putin();	                         /*隨機位置放入數字*/
				square();	                            /*印出putin後的畫面*/

				if (over >= hard)
					for (j = 1; hard >= j; j++)
						putin();	                         /*隨機位置放入數字*/
				square();	                            /*印出putin後的畫面*/
			}
			k = 0;
			point();	                           /*檢查是否還可以移動*/
			if (replay == 'Y') {
				putin();
				putin();
				restart();
				score = 0;
				square();
				replay = 0;
			}
			checking = 0;	                        /*歸0，用以下次檢查*/
		}
		if (ch == ' ') {
			reset();
			putin();
			putin();
			square();
		}
	}
}

