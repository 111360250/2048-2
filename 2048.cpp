#include <stdio.h>         
#include <stdlib.h>
#include <conio.h>   //�b�Y�����Y��
#include <time.h>
#include <windows.h>//Sleep�ݭn���禡

int sum[4][4];	                                 //4*4����l���ҧt���Ʀr 
int num[4][4];	                                 //�ˬd�O�_������ 
int check;	           							 //�ˬd�O�_������V�A�H�ѨM�D�{���j��]�⦸�����D 
int checking = 0;	                             //�ˬd�O�_�٥i�H���� 
int over;
int temp[8] = { 2,2,2,2,2,2,2,4 };	             //7:1�}�C 
char ch;	                                     //���V�� 
char replay;	                                 //�O�_���� 
int max = 0;	                                 //�̰��� 
int score = 0;                                   //���� 
int hard;
	                                     //�C������ 
void start()
{
	int i, j, k = 0;
	printf("\n\n\n\n\n\n�w��Ө�2048!");
	printf("\n\n\n �п�ܹC������(�C�����ʥͦ��X�Ӽ�)\n");
	printf("\n��ĳ 1 �� 2 (���i�j��5) : ");
	scanf("%d", &hard);
	while (hard > 5)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n�w��Ө�2048!");
		printf("\n\n\n�����F!!!!!!!!!!\n");
		printf("\n\n �Э��s��J(���i�j��5) : ");
		scanf("%d", &hard);
	}
	if (hard > 2)
		printf("\n�j��2�i��˸m�C�����׹L�j!�а��n�ǳ�!\n\n");
	Sleep(800);
	printf("\n\n �խ�:");
	Sleep(1000);
	printf("���l޳\n    ���a��\n      ���v��\n");
	Sleep(3000);
	system("cls");
	for (j = 1; 3 >= j; j++)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n ");
		Sleep(400);
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n    �C���}�l!");
		Sleep(650);
	}
	Sleep(500);
}

void restart()                                    //���s�}�l�ɪ���J�e��
{
	system("cls");
	printf("\n\n\n\n\n\n\n�п�ܹC������(�C�����ʥͦ��X�Ӽ�)\n");
	printf("\n\n��ĳ 1 �� 2 (���i�j��5) : ");
	scanf("%d", &hard);
	while (hard > 5)
	{
		system("cls");
		printf("\n\n\n\n\n\n\n�����F!!!(���i�j��5)!!!!!!!\n");
		printf("\n\n      �Э��s��J : ");
		scanf("%d", &hard);
	}
	if (hard > 2)
		printf("\n\n �j��2�i��˸m�C�����׹L�j!�а��n�ǳ�!\n\n");
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

void putin() 
{
	srand(time(NULL));
	int i, j;	                         //�ζüƿ�ܪ��y��
	int k;	                   			 //�M�w��J2��4 /*7:1�����v��J2��4*/                                        
	while (1)	                         /*�y�Ь�0�ɤ~�|��J�Ʀr�ø��X*/
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

