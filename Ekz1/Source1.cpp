#include <stdio.h>
#include <iostream>
#include <malloc.h>
#include <math.h>

const int const_rows = 100, const_cols = 100;

int FillingA(int matrA[const_rows][const_cols], int rows, int cols)
{
	int maxA = matrA[0][0];
	printf("������� �������� ������� A:\n");
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
		printf_s("������� ���������� ����� � ��������: "); scanf_s("%i%i", &rows, &cols);
	} while (rows > const_rows || cols > const_cols || rows <= 0 || cols <= 0);

	int matrA[const_rows][const_cols];
	int matrB[const_rows][const_cols];

	int maxA = FillingA(matrA, rows, cols);
	printf("MAx %d", maxA);

	// ������������ ������� B
	int maxB = matrA[0][0]; // ������������ ������� ������� B
	int maxColumnIndex = 0; // ������ ������� � ������������ ��������� ������� B
	double columnSum = 0; // ����� ��������� ������� � ������������ ���������

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

			// ����� ������������� �������� � ������� �������
			if (matrB[i][j] > maxB) 
			 {
				maxB = matrB[i][j];
				maxColumnIndex = j;
			}
		}
	}

	// ���������� �������� ��������������� ��������� �������
	for (int i = 0; i < rows; i++) {
		columnSum += matrB[i][maxColumnIndex];
	}

	double columnAverage = columnSum / rows;

	// ����� ������� B
	printf("������� B:\n");
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			printf("%d\t", matrB[i][j]);
		}
		printf("\n");
	}

	printf("������� �������������� ��������� ������� %d: %.2f\n", maxColumnIndex, columnAverage);

	return 0;
}