#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 100
#define M 2 * N - 1
#define ElemType int

typedef struct
{
	int weight;
	int parent;
	int leftChild;
	int rightChild;
} HuffmanTreeNode, HuffmanTree[M + 1];

typedef char *HuffmanCode[N+1];

void creatArray(int *count, int *w);
void creatHurrmanTree(HuffmanTree ht, int w[], int n);
void selectMin(HuffmanTree ht, int x, int *s1, int *s2);
void creatEncode(HuffmanTree ht, HuffmanCode hc, int n);

int main(int argc, char const *argv[])
{
	int count;
	ElemType w[N];
	HuffmanTree ht;
	HuffmanCode hc;
	creatArray(&count, w);
	creatHurrmanTree(ht, w, count);
	creatEncode(ht, hc, count);
	return 0;
}

void selectMin(HuffmanTree ht, int x, int *s1, int *s2)
{
	int i;
	int tempMinIndex;
	// printf("\n");
	for (i = 1; i <= x; i++)
	{
		if (ht[i].parent == 0)
		{
			tempMinIndex = i;
			break;
		}
	}
	for (i = 1; i <= x; i++)
	{
		if (ht[i].parent == 0)
		{
			if (ht[i].weight < ht[tempMinIndex].weight)
			{
				tempMinIndex = i;
			}
		}
	}
	*s1 = tempMinIndex;
	for (i = 1; i <= x; i++)
	{
		if (ht[i].parent == 0 && i != *s1)
		{
			tempMinIndex = i;
			break;
		}
	}
	for (i = 1; i <= x; i++)
	{
		if (ht[i].parent == 0 && i != *s1)
		{
			if (ht[i].weight < ht[tempMinIndex].weight)
			{
				tempMinIndex = i;
			}
		}
	}
	*s2 = tempMinIndex;
	// printf("s1 = %d\ts2 = %d\n", ht[*s1].weight, ht[*s2].weight);
}

void creatHurrmanTree(HuffmanTree ht, int w[], int n)
{
	int i;
	int m = 2 * n - 1;
	int allMin = 0;
	ElemType s1, s2;
	for (i = 1; i <= n; i++)
	{
		ht[i].weight = w[i];
		ht[i].leftChild = 0;
		ht[i].rightChild = 0;
		ht[i].parent = 0;
	}
	for (i = n + 1; i <= m; i++)
	{
		ht[i].leftChild = 0;
		ht[i].rightChild = 0;
		ht[i].parent = 0;
	}
	for (i = n + 1; i <= m; i++)
	{
		selectMin(ht, i - 1, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[i].leftChild = s1;
		ht[i].rightChild = s2;
		ht[s1].parent = i;
		ht[s2].parent = i;
	}
	// for (i = n + 1; i <= m; i++)
	// {
	// 	allMin += ht[i].weight;
	// }
	// printf("%d", allMin);
}

void creatArray(int *count, int *w)
{
	int i;
	scanf("%d", count);
	for (i = 1; i <= *count; i++)
	{
		scanf("%d", &w[i]);
	}
}

void creatEncode(HuffmanTree ht, HuffmanCode hc, int n)
{
	char *cd;
	int i;
	int c, parent;
	int start;
	cd = (char *)malloc(n * sizeof(char *));
	cd[n - 1] = '\0';

	for (i = 1; i <= n; i++)
	{
		start = n - 1;
		for (c = i, parent = ht[i].parent; parent != 0; c = parent, parent = ht[parent].parent)
		{
			if (ht[parent].leftChild == c)
			{
				cd[--start] = '0';
			}
			else
			{
				cd[--start] = '1';
			}
		}
		hc[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);
	}
	free(cd);
	for (i = 1; i <= n; i++)
	{
		printf("%s\n", hc[i]);
	}
}