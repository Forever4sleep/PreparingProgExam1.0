#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <math.h>

const int const_rows = 100, const_cols = 100;

void Gen_Matr_1(double matr[const_rows][const_cols], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i > j)
				matr[i][j] = (i+j)*(i+j)*0.2;
			else if (i == j)
				matr[i][j] = 1.51;
			else
				matr[i][j] = (i - j) * (i - j) * 3.1;
		}
	}
}

double Sred1(double matr[][const_cols], int k, int cols)
{
	double* row = matr[k];
	double sum = 0;

	for (int i = 0; i < cols; i++)
		sum += row[i];
	
	return sum / cols;
}

void PrintScreen(double matr[const_rows][const_cols], int rows, int cols)
{
	printf_s("Данный массив состоит из элементов: \n");
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			printf_s("%5.2f ", matr[i][j]);
		printf_s("\n");
	}
}

double SumMinMax4(double matr[][const_cols], int k, int cols)
{
	double min = matr[k][0];
	double max = matr[k][0];

	for (int j = 1; j < cols; j++)
	{
		if (matr[k][j] < min)
			min = matr[k][j];
		if (matr[k][j] > max)
			max = matr[k][j];
	}

	return min + max;
}

void Transp(double matr[const_rows][const_cols], int rows, int cols)
{
	for (int i = 0; i < rows; i++) {
		for (int j = i+1; j < cols; j++) {
			int temp = matr[i][j];
			matr[i][j] = matr[j][i];
			matr[j][i] = temp;
		}
	}
}


void Task1()
{
	int rows = 0, cols = 0, k;
	double matr[const_rows][const_cols];

	do
	{
		printf_s("Введите количество строк и столбцов: "); scanf_s("%i%i", &rows, &cols);
	} while (rows > const_rows || cols > const_cols || rows <=0 || cols <=0);

	Gen_Matr_1(matr, rows, cols);

	PrintScreen(matr, rows, cols);

	Transp(matr, rows, cols);

	PrintScreen(matr, cols, rows);


	do
	{
		printf_s("Введите номер строки: "); scanf_s("%i", &k);
	} while (k < 0 || k > rows-1);

	double sred = Sred1(matr, k, cols);
	double sum_minmax = SumMinMax4(matr, k , cols);

	printf("Сред. арифм  = %.2f\n", sred);
	printf("Сумма мин и макс  = %.3f\n", sum_minmax);
}

void Gen_Matr_3(double matr[const_rows][const_cols], int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (i > j)
				matr[i][j] = i + j;
			else
				matr[i][j] = i - j;
		}
	}
}

void calculate_column_sum(double matrix[][100], int n, int m) {
	int column_sum[100] = { 0 }; // Массив для хранения суммы каждого столбца

	// Вычисление суммы каждого столбца
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			column_sum[j] += matrix[i][j];
		}
	}

	// Вывод суммы каждого столбца
	printf("Сумма каждого столбца:\n");
	for (int j = 0; j < m; j++) {
		printf("Столбец %d: %d\n", j + 1, column_sum[j]);
	}
}
int FindMinPoboch3(double matr[][const_cols], int rows, int cols)
{
	int max = matr[1][0];
	for (int i = 2; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (matr[i][j] > max && j<i)
			{
				max = matr[i][j];
			}
		}
	}
	return max;
}


void Task3()
{
	int rows = 0, cols = 0;
	double matr[const_rows][const_cols];

	do {
		printf_s("Введите количество строк и столбцов: "); scanf_s("%i%i", &rows, &cols);
	} while (rows > const_rows || cols > const_cols || rows <= 0 || cols <= 0 || rows != cols);

	Gen_Matr_3(matr, rows, cols);

	PrintScreen(matr, rows, cols);

	calculate_column_sum(matr, rows, cols);

	int min = FindMinPoboch3(matr, rows, cols);

	printf(" Min = %d", min);
}

int main1()
{
	system("chcp 1251");

	//Task1();
	Task3();

	return 0;
}