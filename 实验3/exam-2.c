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
	gets(inStr);
	gets(postStr);
	return strlen(inStr);
}

BinaTree creatBinaTree(ElemType *inStr, ElemType *postStr, int strlen)
{
	BinaTree tree;
	int k;
	char *root;
	root = postStr[strlen - 1];
	tree = (BinaTree)malloc(sizeof(BinaNode));
	for (root = inStr; root < inStr + strlen; root++)
	{
		if (*root == *(postStr + strlen - 1))
		{
			k = root - inStr;
			tree->data = *root;
			break;
		}
		else
		{
			return NULL;
		}
	}
	tree->LeftChild = creatBinaTree(inStr, postStr, k);
	tree->RightChild = creatBinaTree(inStr + k + 1, postStr + k, strlen - k - 1);
	return tree;
}

void postOrder(BinaTree tree)
{
	if (tree != NULL)
	{
		postOrder(tree->LeftChild);
		postOrder(tree->RightChild);
		printf("%c", tree->data);
	}
	else
	{
		printf("#");
	}
}

int main(int argc, char const *argv[])
{
	ElemType inStr[100], postStr[100];
	BinaTree tree;
	int strLen;
	strLen = initStr(inStr, postStr);
	tree = creatBinaTree(inStr, postStr, strLen);
	postOrder(tree);
	return 0;
}
