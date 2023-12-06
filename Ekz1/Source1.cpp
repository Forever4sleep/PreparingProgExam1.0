#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <math.h>

const int const_rows = 100, const_cols = 100;

int FillingA(int matrA[const_rows][const_cols], int rows, int cols)
{
	int maxA = matrA[0][0];
	printf("Введите элементы матрицы A:\n");
	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			scanf_s("%d", &matrA[i][j]);

			if (matrA[i][j] > maxA) 
				maxA = matrA[i][j];
		}
	}
	return maxA;
}

int main()
{
	system("chcp 1251");

	int rows, cols;

	do
	{
		printf_s("Введите количество строк и столбцов: "); scanf_s("%i%i", &rows, &cols);
	} while (rows > const_rows || cols > const_cols || rows <= 0 || cols <= 0);

	int matrA[const_rows][const_cols];
	int matrB[const_rows][const_cols];

	int maxA = FillingA(matrA, rows, cols);
	printf("MAx %d", maxA);

	// Формирование матрицы B
	int maxB = matrA[0][0]; // Максимальный элемент матрицы B
	int maxColumnIndex = 0; // Индекс столбца с максимальным элементом матрицы B
	double columnSum = 0; // Сумма элементов столбца с максимальным элементом

	for (int i = 0; i < rows; i++) 
	{
		for (int j = 0; j < cols; j++) 
		{
			if (i > j) 
			{
				matrB[i][j] = (double)maxA / (i - j);
			}
			else if (i == j)
			{
				matrB[i][j] = sin(matrA[i][j]);
			}
			else 
			{
				matrB[i][j] = (double)maxA / (j - i);
			}

			// Поиск максимального элемента и индекса столбца
			if (matrB[i][j] > maxB) 
			 {
				maxB = matrB[i][j];
				maxColumnIndex = j;
			}
		}
	}

	// Вычисление среднего арифметического элементов столбца
	for (int i = 0; i < rows; i++) {
		columnSum += matrB[i][maxColumnIndex];
	}

	double columnAverage = columnSum / rows;

	// Вывод матрицы B
	printf("Матрица B:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", matrB[i][j]);
		}
		printf("\n");
	}

	printf("Среднее арифметическое элементов столбца %d: %.2f\n", maxColumnIndex, columnAverage);

	return 0;
}