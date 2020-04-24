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
} HuffmanTreeNode, HuffmanTree[M+1];

typedef char *HuffmanCode[N];

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
	for (i = 0; i < x; i++)
	{
		if (ht[i].parent == 0)
		{
			tempMinIndex = i;
			break;
		}
	}
	for (i = 0; i < x; i++)
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
	for (i = 0; i < x; i++)
	{
		if (ht[i].parent == 0 && i != *s1)
		{
			tempMinIndex = i;
			break;
		}
	}
	for (i = 0; i < x; i++)
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
}

void creatHurrmanTree(HuffmanTree ht, int w[], int n)
{
	int i;
	int m = 2 * n - 1;
	int allMin = 0;
	ElemType s1, s2;
	for (i = 0; i < n; i++)
	{
		ht[i].weight = w[i];
		ht[i].leftChild = 0;
		ht[i].rightChild = 0;
		ht[i].parent = 0;
	}
	for (i = n; i < m; i++)
	{
		ht[i].leftChild = 0;
		ht[i].rightChild = 0;
		ht[i].parent = 0;
	}
	for (i = n; i < m; i++)
	{
		selectMin(ht, i, &s1, &s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[i].leftChild = s1;
		ht[i].rightChild = s2;
		ht[s1].parent = i;
		ht[s2].parent = i;
	}
}

void creatArray(int *count, int *w)
{
	int i;
	scanf("%d", count);
	for (i = 0; i < *count; i++)
	{
		scanf("%d", &w[i]);
	}
}

void creatEncode(HuffmanTree ht, HuffmanCode hc, int n)
{
	char *cd;
	int m = 2 * n - 1;
	int i;
	int c, p;
	int start;
	cd = (char *)malloc((n) * sizeof(char));
	cd[n-1] = '\0';
	printf("hello world");

	for (i = 0; i < n; i++)
	{
		printf("hello world");
		start = n-1;
		c = i;
		p = ht[i].parent;
		while (p != 0)
		{
			start--;
			if (ht[p].leftChild == c)
			{
				cd[start] = '0';
			}
			else
			{
				c = p;
				p = ht[p].parent;
			}
		}
		hc[i] = (char *)malloc((n - start) * sizeof(char));
		strcpy(hc[i], &cd[start]);
		printf("%s\t", hc[i]);
	}
	free(cd);
}