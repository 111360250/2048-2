#include <stdio.h>         
#include <stdlib.h>
#include <conio.h>   //�b�Y�����Y��
#include <time.h>
#include <windows.h>//Sleep�ݭn���禡

int sum[4][4];	                                  //4*4����l���ҧt���Ʀr 
int num[4][4];	                                         //�ˬd�O�_������ 
int check;	            //�ˬd�O�_������V�A�H�ѨM�D�{���j��]�⦸�����D 
int checking = 0;	                                 //�ˬd�O�_�٥i�H���� 
int over;
int temp[8] = { 2,2,2,2,2,2,2,4 };	                                //7:1�}�C 
char ch;	                                                   //���V�� 
char replay;	                                               //�O�_���� 
int max = 0;	                                                 //�̰��� 
int score = 0;                                                     //���� 
int hard;	                                                   //�C������ 
void start()
{

}
void restart()                                    //���s�}�l�ɪ���J�e��
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
void lave() {	                 //�Y�Ѿl���ŭӼƤp��w�]�ͦ��ƥi�~��ͦ� 
	

}
void move() {
	
}




void plus() {
	
}
int point() {
	
}
void reset() {
	
}
int main(int argc, char* argv[]) {
	start();
	int i, j;	                                          //�y�� / �j���
	int k = 0;	                                                 //�ˬd�� 
	/*��J0(�ť�)*/
	for (i = 0; i < 4; i++) {
		for (j = 0; j < 4; j++)
			sum[i][j] = 0;
	}
	putin();	                                     /*�}���ɦ���ӼƦr*/
	putin();
	square();
	while (1) {
		check = 0;	                       /*���k0�A������V�~�[1*/
		ch = getch(); 	/*���V*/
		if (ch == 72 || ch == 75 || ch == 77 || ch == 80) { check = 1; }		 /*�������*/
		copy();		                           /*�ƻs�Ʀr�᭱�ˬd��*/
		move();		                                    /*���ʼƦr*/
		plus();		                                /*�۾F�Ʀr�ۥ[*/
		move();		                           /*�ۥ[����A���ʤ@��*/
		if (check != 0) {	                              /*����V�~�|�~��*/
			square();	                 /*���L�X���ʧ��A�٨Sputin���e��*/
			for (i = 0; i < 4; i++)	                       /*�ˬd�O�_������*/
				for (j = 0; j < 4; j++)
					if (num[i][j] == sum[i][j])
						k++;
			Sleep(200);
			if (k != 16) {	                             /*�����ʤ~putin*/
				lave();

				if (over < hard)
					for (j = 1; over >= j; j++)
						putin();	                         /*�H����m��J�Ʀr*/
				square();	                            /*�L�Xputin�᪺�e��*/

				if (over >= hard)
					for (j = 1; hard >= j; j++)
						putin();	                         /*�H����m��J�Ʀr*/
				square();	                            /*�L�Xputin�᪺�e��*/
			}
			k = 0;
			point();	                           /*�ˬd�O�_�٥i�H����*/
			if (replay == 'Y') {
				putin();
				putin();
				restart();
				score = 0;
				square();
				replay = 0;
			}
			checking = 0;	                        /*�k0�A�ΥH�U���ˬd*/
		}
		if (ch == ' ') {
			reset();
			putin();
			putin();
			square();
		}
	}
}

