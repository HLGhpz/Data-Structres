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

int initStr(ElemType * inStr, ElemType * postStr){
	char str[200];
	int number;
	gets(str);
	sscanf(str, "%s %s", inStr, postStr);
	return strlen(inStr);
}

void creatBinaTree(ElemType *inStr, ElemType *postStr, int strlen)
{
	char root;
	root = postStr[strlen - 1];
}

int main(int argc, char const *argv[])
{
	ElemType inStr[100], postStr[100];
	int strLen;
	strLen = initStr(inStr, postStr);
	creatBinaTree(inStr, postStr, strLen);
	return 0;
}

