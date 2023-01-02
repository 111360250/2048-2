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

}
void restart()                                    //重新開始時的輸入畫面
{
	
}
void bye()
{
	
}
void putin() {
	
}

void square()
{
	
}
void copy()
{
	
}
void lave() {	                 //若剩餘的空個數小於預設生成數可繼續生成 
	

}
void move() {
	
}




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

