#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 100
#define ElemType char
#define True 1
#define False 0

int countP = 0;
int countQ = 0;
char pStr[50];
char qStr[50];

typedef struct Node
{
	ElemType data;
	struct Node *LeftChild;
	struct Node *RightChild;
} BinaNode, *BinaTree;

int initStr(ElemType *preStr, ElemType *inStr, ElemType *p, ElemType *q)
{
	char temp[5];
	int number;
	scanf("%s", preStr);
	scanf("%s", inStr);
	gets(temp);
	sscanf("%c %c", p, q);
	return strlen(preStr);
}

BinaTree creatBinaTree(ElemType *preStr, ElemType *inStr, int strlen)
{
	// printf("ok1\n");
	BinaTree tree;
	int i;
	if (strlen == 0)
	{
		return NULL;
	}
	tree = (BinaTree)malloc(sizeof(BinaNode));
	tree->data = preStr[0];
	for (i = 0; i < strlen; i++)
	{
		if (preStr[0] == inStr[i])
		{
			break;
		}
	}
	tree->LeftChild = creatBinaTree(preStr + 1, inStr, i);
	tree->RightChild = creatBinaTree(preStr + i + 1, inStr + i + 1, strlen - i - 1);
	return tree;
}

int getPath(BinaTree root, ElemType *ch)
{
	if (root == NULL)
	{
		return False;
	}
	pStr[countP] = root->data;
	if (root->data == *ch)
	{
		return True;
	}
	if (getPath(root->LeftChild, ch))
	{
		return True;
	}
	if (getPath(root->RightChild, ch))
	{
		return True;
	}
}

int main(int argc, char const *argv[])
{
	ElemType preStr[100], inStr[100];
	ElemType *p, *q;
	BinaTree tree;
	int strLen;
	strLen = initStr(preStr, inStr, p, q);
	tree = creatBinaTree(preStr, inStr, strLen);
	printf("NULL");
	getPath(tree, p);
	return 0;
}
