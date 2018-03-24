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
	printf("Введите номер задания\nN = ");

	scanf("%d", &N1);

	if (N1 == 1)
	{
		/*1.	Составить программу, которая запрашивает название романа и фамилию его автора, а затем выводит сообщение 
			: "Писатель ... — автор романа ..." (на месте многоточий должны быть выведены соответствующие значения)*/
		char NameR[20];
		char NameA[10];

		printf("Введите название романа\n");
		scanf("%s", NameR);

		printf("\nВведите автора романа\n");
		scanf("%s", NameA);

		printf("Название романа: %s, автор: %s\n", NameR, NameA);
	}
	else if (N1 == 2)
	{
		/*2.	Даны названия двух стран.Присвоить эти названия переменным величинам s1 и s2, 
			после чего название s2 присвоить величине t1, название s1 — величине t2.*/

		char s1[15];
		char s2[15];

		char t1[15];
		char t2[15];

		printf("Введите название первого города\n");
		scanf("%s", s1);

		printf("Введите название второго города\n");
		scanf("%s", s2);

		strcpy(t1, s1);
		strcpy(t2, s2);

		printf("Первый город:\n%s\n", t1);
		printf("Второй город:\n%s\n", t2);
	}
	else if (N1 == 3)
	{
		/*3.	Дано слово.Вывести на экран его последний символ.*/

		char slovo[] = "get";

		printf("Слово содержит %d символов\nПоследняя буква: %c\n", strlen(slovo), slovo[strlen(slovo)-1]);
	}
	else if (N1 == 4)
	{
		/*4.	Дано слово.Вывести на экран его k - й символ*/

		char slovo1[] = "Синхрофазатрон";
		int N=0;

		printf("Введите номер буквы N = ");
		scanf("%d", &N);

		printf("Ваша буква: %c\n", slovo1[N - 1]);
	}
	else if (N1 == 10)
	{
		/*10.	Дано слово, состоящее из четного числа букв.Вывести на экран его первую половину, не используя оператор цикла.*/

		char slovo[] = "города";

		slovo[strlen(slovo) / 2] = '\0';

		printf("Половина слова: %s\n", slovo);
	}
	else if (N1 == 11)
	{
		/*11.	Введите массив символов из 10 элементов.Замените символы - цифры на символ '*'.*/

		char simvoli[] = "hjjhvjhvs65kj4";
		for (int i = 0; i < strlen(simvoli); i++)
		{
			if ((int)simvoli[i] >= 48 && (int)simvoli[i] <= 57)
				simvoli[i] = '*';
		}

		printf("Ваше слово: %s\n", simvoli);
	}
	else if (N1 == 12)
	{
		/*12.	Введите массив символов из 11 элементов.Переведите все строчные буквы - символы в верхний регистр*/
		/*for (int i = 0; i <= 256; i++)
		{
			printf("%d - %c\n", i, i);
		}*/

		char arr[] = "алматы";

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
			printf("Память не выделена");
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
		/*a.Сформировать одномерный массив, каждый элемент которого равен сумме четных положительных 
			элементов соответствующего столбца двумерного массива*/

		int *a = NULL;
		int *b = NULL;
		int Str = 0;
		int Col = 0;

		srand(time(0));

		printf("Введите количесво строк массива Str = ");
		scanf("%d", &Str);
		printf("Введите количесво столбцов массива Col = ");
		scanf("%d", &Col);

		a = (int *)malloc((Str*Col)*sizeof(int));
		b = (int *)malloc((Col)*sizeof(int));

		if (a == NULL || b == NULL)
		{
			printf("Память не выделена");
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