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
	ElemType temp_col = 0;
	ElemType temp_row = 0;
	int number;
	int i;
	M->len = 0;
	scanf("%d", &M->r);
	scanf("%d", &M->c);

	for (i = 0; i < M->r * M->c; i++)
	{
		scanf("%d", &temp);
		if (temp != 0)
		{
			M->data[M->len].e = temp;
			M->data[M->len].col = temp_col;
			M->data[M->len].row = temp_row;
			M->len++;
		}

		if (temp_col < M->c - 1)
		{
			temp_col++;
		}
		else
		{
			temp_col = 0;
			temp_row++;
		}
	}
}

void transMatrix(Matrix A, Matrix * B)
{
	int col, t, p, q;
	int cnum[Maxsize], cpos[Maxsize];
	B->len = A.len;
	B->c = A.r;
	B->r = A.c;
	for (col=0; col < A.c; col++)
	{
		cnum[col] = 0;
	}
	for (t=0; t < A.len; t++){
		cnum[A.data[t].col]++;
	}
	cpos[0] = 1;
	for (col = 1; col < A.r; col++)
	{
		cpos[col] = cpos[col - 1] + cnum[col - 1];
	}

	for (p = 0; p < A.len-1; p++)
	{
		col = A.data[p].col;
		q = cpos[col];
		B->data[q].row = A.data[p].col;
		B->data[q].col = A.data[p].row;
		B->data[q].e = A.data[p].e;
		cpos[col]++;
	}
}

void outputMatrix(Matrix M)
{
	int temp_row;
	int temp_col;
	int index = 0;
	for (temp_row = 0; temp_row < M.r; temp_row++)
	// 行
	{
		for (temp_col = 0; temp_col < M.c; temp_col++)
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
	Matrix A, B;
	initMatrix(&A);
	transMatrix(A, &B);
	outputMatrix(A);
	return 0;
}

