#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <Windows.h>
#include <time.h>


void main() {
	
	setlocale(LC_ALL, "Rus");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N1 = 0;
	printf("������� ����� �������\nN = ");

	scanf("%d", &N1);

	if (N1 == 1)
	{
		/*1.	��������� ���������, ������� ����������� �������� ������ � ������� ��� ������, � ����� ������� ��������� 
			: "�������� ... � ����� ������ ..." (�� ����� ���������� ������ ���� �������� ��������������� ��������)*/
		char NameR[20];
		char NameA[10];

		printf("������� �������� ������\n");
		scanf("%s", NameR);

		printf("\n������� ������ ������\n");
		scanf("%s", NameA);

		printf("�������� ������: %s, �����: %s\n", NameR, NameA);
	}
	else if (N1 == 2)
	{
		/*2.	���� �������� ���� �����.��������� ��� �������� ���������� ��������� s1 � s2, 
			����� ���� �������� s2 ��������� �������� t1, �������� s1 � �������� t2.*/

		char s1[15];
		char s2[15];

		char t1[15];
		char t2[15];

		printf("������� �������� ������� ������\n");
		scanf("%s", s1);

		printf("������� �������� ������� ������\n");
		scanf("%s", s2);

		strcpy(t1, s1);
		strcpy(t2, s2);

		printf("������ �����:\n%s\n", t1);
		printf("������ �����:\n%s\n", t2);
	}
	else if (N1 == 3)
	{
		/*3.	���� �����.������� �� ����� ��� ��������� ������.*/

		char slovo[] = "get";

		printf("����� �������� %d ��������\n��������� �����: %c\n", strlen(slovo), slovo[strlen(slovo)-1]);
	}
	else if (N1 == 4)
	{
		/*4.	���� �����.������� �� ����� ��� k - � ������*/

		char slovo1[] = "��������������";
		int N=0;

		printf("������� ����� ����� N = ");
		scanf("%d", &N);

		printf("���� �����: %c\n", slovo1[N - 1]);
	}
	else if (N1 == 10)
	{
		/*10.	���� �����, ��������� �� ������� ����� ����.������� �� ����� ��� ������ ��������, �� ��������� �������� �����.*/

		char slovo[] = "������";

		slovo[strlen(slovo) / 2] = '\0';

		printf("�������� �����: %s\n", slovo);
	}
	else if (N1 == 11)
	{
		/*11.	������� ������ �������� �� 10 ���������.�������� ������� - ����� �� ������ '*'.*/

		char simvoli[] = "hjjhvjhvs65kj4";
		for (int i = 0; i < strlen(simvoli); i++)
		{
			if ((int)simvoli[i] >= 48 && (int)simvoli[i] <= 57)
				simvoli[i] = '*';
		}

		printf("���� �����: %s\n", simvoli);
	}
	else if (N1 == 12)
	{
		/*12.	������� ������ �������� �� 11 ���������.���������� ��� �������� ����� - ������� � ������� �������*/
		/*for (int i = 0; i <= 256; i++)
		{
			printf("%d - %c\n", i, i);
		}*/

		char arr[] = "������";

		for (int i = 0; i < strlen(arr); i++)
		{
			*(arr + i) = ((int)*(arr + i)) - 32;
		}

		printf("%s\n", arr);
	}
	else if (N1 == 13)
	{
		int len = 0;
		scanf("%d", &len);

		float *p = NULL;
		//p = (int *)malloc(sizeof(int)*len);
		p = (float *)calloc(len, sizeof(float));
		if (p == NULL)
		{
			printf("������ �� ��������");
			exit(EXIT_FAILURE);
		}
		else
		{
			int i = 0;
			int number = 0;

			printf("%d", len);
			
			printf("Enter val (q for exit): ");
			while (i < len && scanf("%f", &p[i]) == 1)
				i++;

			printf("Enter %d elements: \n", number = i);

			printf("\n-------------------------\n");
			for (i = 0; i < number; i++)
			{
				printf("%7.2f \n", p[i]);
			}
		}
		free(p);
	}
	else if (N1 == 14)
	{
		/*a.������������ ���������� ������, ������ ������� �������� ����� ����� ������ ������������� 
			��������� ���������������� ������� ���������� �������*/

		int *a = NULL;
		int *b = NULL;
		int Str = 0;
		int Col = 0;

		srand(time(0));

		printf("������� ��������� ����� ������� Str = ");
		scanf("%d", &Str);
		printf("������� ��������� �������� ������� Col = ");
		scanf("%d", &Col);

		a = (int *)malloc((Str*Col)*sizeof(int));
		b = (int *)malloc((Col)*sizeof(int));

		if (a == NULL || b == NULL)
		{
			printf("������ �� ��������");
			exit(EXIT_FAILURE);
		}
		else
		{
			for (int i = 0; i < Col; i++)
			{
				for (int j = 0; j < Str; j++)
				{
					*(a + i*Col + j) = -20 + rand() % (50 + 20);
					printf("%d\t", *(a + i*Col + j));
				}
				printf("\n");
			}

			printf("\n");
			int Sum = 0;
			for (int i = 0; i < Col; i++)
			{
				for (int j = 0; j < Str; j++)
				{
					if (*(a + i*Col + j) > 0 && *(a + i*Col + j)%2 == 0)
						Sum += *(a + i*Col + j);
				}

				*(b + i) = Sum;
				printf("%d\n", *(b + i));
				Sum = 0;
			}
		}
	}
	system("pause");
}