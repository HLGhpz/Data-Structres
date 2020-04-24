#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define Maxsize 100
#define ElemType char
#define True 1

typedef struct Node
{
	ElemType data;
	struct Node *LeftChild;
	struct Node *RightChild;
} BinaNode, *BinaTree;

int initStr(ElemType *inStr, ElemType *postStr)
{
	char str[200];
	int number;
	gets(str);
	sscanf(str, "%s %s", inStr, postStr);
	return strlen(inStr);
}

BinaTree creatBinaTree(ElemType *inStr, ElemType *postStr, int strlen)
{
	BinaTree tree;
	int i;
	if (strlen == 0)
	{
		return NULL;
	}
	tree = (BinaTree)malloc(sizeof(BinaNode));
	tree->data = postStr[strlen-1];
	for (i = 0; i < strlen; i++)
	{
		if (postStr[strlen-1] == inStr[i])
		{
			break;
		}
	}
	tree->LeftChild = creatBinaTree(inStr, postStr, i);
	tree->RightChild = creatBinaTree(inStr + i + 1, postStr + i, strlen - i - 1);
	return tree;
}

void preOrder(BinaTree tree)
{
	if (tree != NULL)
	{
		printf("%c", tree->data);
		preOrder(tree->LeftChild);
		preOrder(tree->RightChild);
	}
}

int main(int argc, char const *argv[])
{
	ElemType inStr[100], postStr[100];
	BinaTree tree;
	int strLen;
	strLen = initStr(inStr, postStr);
	tree = creatBinaTree(inStr, postStr, strLen);
	preOrder(tree);
	return 0;
}
