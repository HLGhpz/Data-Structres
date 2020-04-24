#include <stdio.h>

#define Maxsize 100
#define ElemType int
#define True 1

typedef struct
{
	ElemType row, col;
	ElemType e;
} Triple;

typedef struct
{
	Triple data[Maxsize];
	int r, c, len;
} Matrix;

void initMatrix(Matrix *M)
{
	ElemType temp;
	ElemType temp_col = 1;
	ElemType temp_row = 1;
	int number;
	int i;
	M->len = 0;
	scanf("%d", &M->r);
	scanf("%d", &M->c);

	for (i = 1; i <= M->r * M->c; i++)
	{
		scanf("%d", &temp);
		if (temp != 0)
		{
			M->data[M->len].e = temp;
			M->data[M->len].col = temp_col;
			M->data[M->len].row = temp_row;
			M->len++;
		}

		if (temp_col <= M->c - 1)
		{
			temp_col++;
		}
		else
		{
			temp_col = 1;
			temp_row++;
		}
	}
	// for (i = 0; i < M->len; i++)
	// {
	// 		printf("%d, %d, %d", M->data[i].row, M->data[i].col, M->data[i].e);
	// }

}

void transMatrix(Matrix a, Matrix *b)
{
	int i, j, k;
	printf("in trans");
	b->len = a.len;
	b->r = a.c;
	b->c = a.r;
	int pos[Maxsize], num[Maxsize];
	for (i = 1; i <= a.c; i++)
		num[i] = 0;
	for (i = 1; i <= a.len; i++)
		num[a.data[i].col]++;
	pos[1] = 1;
	for (j = 2; j <= a.c; j++)
		pos[j] = pos[j - 1] + num[j - 1];
	for (i = 1; i <= a.len; i++)
	{
		j = a.data[i].col;
		k = pos[j];
		b->data[k].col = a.data[i].row;
		b->data[k].row = a.data[i].col;
		b->data[k].e = a.data[i].e;
		pos[j]++;
	}
	printf("out for");
}

void outputMatrix(Matrix M)
{
	int temp_row;
	int temp_col;
	int index = 0;

	for (temp_row = 1; temp_row <= M.r; temp_row++)
	// 行
	{
		for (temp_col = 1; temp_col <= M.c; temp_col++)
		// 列
		{
			if (temp_row == M.data[index].row && temp_col == M.data[index].col)
			{
				printf("%d ", M.data[index].e);
				index++;
			}
			else
			{
				printf("%d ", 0);
			}
		}
		printf("\n");
	}
}

int main(int argc, char const *argv[])
{
	Matrix A, b;
	initMatrix(&A);
	printf("init");
	transMatrix(A, &b);
	printf("tran");
	outputMatrix(b);
	return 0;
}
