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
	printf("�©[�M\n      ���T��\n      ���v��\n");
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
void putin() {
	srand(time(NULL));
	int i, j;	                                       //�ζüƿ�ܪ��y��
	int k;	                   //�M�w��J2��4 /*7:1�����v��J2��4*/                                        
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
	system("cls");	                    /*�M�ŵe���A���s���e�����л\�ª�*/
	int i, j;	                                                 //�j���
	int k = 0;
	printf("\n\n\n  �̰�����:%d   ��e����:%d\n", max, score);
	/*�L�X4*4��l*/
	printf("\n\n----------------------------\n");
	for (i = 0; i < 4; i++) {
		printf("|");
		for (j = 0; j < 4; j++)
		{
			if (sum[i][j] == 0)	                /*�p�G�y�Ь�0�ɤ��L�Ʀr*/
				printf("     | ");
			else
				printf("%4d | ", sum[i][j]);
		}
		printf("\n----------------------------\n");
	}
	printf("\n  ���s�}�l�Ы��ť���\n");
	for (i = 0; 4 > i; i++)
		for (j = 0; 4 > j; j++)
		{
			if (sum[i][j] > 0)
				k++;
		}
	if (k >= 16)
	{
		printf("\n\n�[�o��!����!");
	}
	printf("\n\n\n�խ�:�©[�M");
	printf("\n���T��");
	printf("\n���v��");
}
void copy()
{
	int i, j, k;	                                          //�y�� / �j���
	for (i = 0; i < 4; i++)
		for (j = 0; j < 4; j++)
			num[i][j] = sum[i][j];
}
void lave() {	                 //�Y�Ѿl���ŭӼƤp��w�]�ͦ��ƥi�~��ͦ� 
	int i, j;
	over = 0;
	for (j = 0; 4 > j; j++)
		for (i = 0; 4 > i; i++)
			if (sum[i][j] == 0)
				over++;

}
void move() {
	int i, j, k;	                                          //�y�� / �j��� 
	int temp;                                               //�Ȧs�Ʀr 

	if (ch == 75)	                                  /*��������(�p�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j] == 0 && sum[i][j + 1] > 0) {
						temp = sum[i][j];
						sum[i][j] = sum[i][j + 1];
						sum[i][j + 1] = temp;
					}
	if (ch == 77)	                                  /*���k����(�j�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[i][j + 1] == 0 && sum[i][j] > 0) {
						temp = sum[i][j + 1];
						sum[i][j + 1] = sum[i][j];
						sum[i][j] = temp;
					}
	if (ch == 72)	                                  /*���W����(�p�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j][i] == 0 && sum[j + 1][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	if (ch == 80)	                                 /*���U����(�j�y��)*/
		for (i = 0; i < 4; i++)
			for (k = 0; k < 4; k++)
				for (j = 0; j < 3; j++)
					if (sum[j + 1][i] == 0 && sum[j][i] > 0) {
						temp = sum[j][i];
						sum[j][i] = sum[j + 1][i];
						sum[j + 1][i] = temp;
					}
	for (i = 0; i < 4; i++)	                                   /*�M��̤j��*/
		for (j = 0; j < 4; j++)
			if (score > max)
				max = score;
}



/*
	��L(�W) 72
	��L(�U) 80
	��L(��) 75
	��L(�k) 77

�y��(sum[i][j]):
	00	01	02	03
	10	11	12	13
	20	21	22	23
	30	31	32	33
*/
void plus() {
	int i, j;	                                                   //�y�� 
	if (ch == 75)	                                  /*��������(�p�y��)*/
		for (i = 0; i < 4; i++)
			for (j = 0; j < 3; j++)
				if (sum[i][j] == sum[i][j + 1]) {
					sum[i][j] += sum[i][j + 1];
					sum[i][j + 1] = 0;
					score += sum[i][j];
				}
	if (ch == 77)	                                  /*���k����(�j�y��)*/
		for (i = 0; i < 4; i++)
			for (j = 3; j >= 0; j--)
				if (sum[i][j] == sum[i][j - 1]) {
					sum[i][j] += sum[i][j - 1];
					sum[i][j - 1] = 0;
					score += sum[i][j];
				}
	if (ch == 72)	                                  /*���W����(�p�y��)*/
		for (i = 0; i < 4; i++)
			for (j = 0; j < 3; j++)
				if (sum[j][i] == sum[j + 1][i]) {
					sum[j][i] += sum[j + 1][i];
					sum[j + 1][i] = 0;
					score += sum[j][i];
				}
	if (ch == 80)	                                  /*���U����(�j�y��)*/
		for (i = 0; i < 4; i++)
			for (j = 3; j >= 0; j--)
				if (sum[j][i] == sum[j - 1][i]) {
					sum[j][i] += sum[j - 1][i];
					sum[j - 1][i] = 0;
					score += sum[j][i];
				}
}
int point() {
	int i, j;	                                                   //�y�� 

	for (i = 0; i < 4; i++)	                                  /*�M��O�_��0*/
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
		int i, j;	                                               //�y�� 
		printf("\n\n                                                    YOU LOSE!!!");
		Sleep(3000);
		system("cls");
		printf(" \n\n\n                                                  �C������\n\n\n\n");
		printf("  ������:%d   �̰���:%d\n\n\n\n", score, max);
		printf("�O�_���s�}�l(Y/N) ? ");
		scanf(" %c", &replay);
		if (replay == 'Y') {
			for (i = 0; i < 4; i++)	                             /*�M�żƦr*/
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
	for (i = 0; i < 4; i++)	                                     /*�M�żƦr*/
		for (j = 0; j < 4; j++)
			sum[i][j] = 0;
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

