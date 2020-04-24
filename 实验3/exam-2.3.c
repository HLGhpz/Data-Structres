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

int initStr(ElemType *inStr, ElemType *postStr, BinaTree nodeP, BinaTree nodeQ)
{
	nodeP = (BinaTree)malloc(sizeof(BinaNode));
	nodeQ = (BinaTree)malloc(sizeof(BinaNode));
	scanf("%s", inStr);		//获取中序序列
	scanf("%s", postStr); //获取后序序列

	getchar();
	nodeP->data = getchar();
	nodeQ->data = getchar();
	return strlen(inStr); //获取结点个数
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
	tree->data = postStr[strlen - 1];
	for (i = 0; i < strlen; i++)
	{
		if (postStr[strlen - 1] == inStr[i])
		{
			break;
		}
	}
	tree->LeftChild = creatBinaTree(inStr, postStr, i);
	tree->RightChild = creatBinaTree(inStr + i + 1, postStr + i, strlen - i - 1);
	return tree;
}

BinaTree findCommonAncestor(BinaNode *root, BinaNode *p, BinaNode *q)
{
	if (root == p || root == q || !root)
	{
		printf("1");
		return root;
	}

	BinaNode *left = findCommonAncestor(root->LeftChild, p, q);
	BinaNode *right = findCommonAncestor(root->RightChild, p, q);

	if (!left && !right)
	{
		printf("2");
		return NULL;
	}
	else if (left && !right)
	{
		printf("3");
		return left;
	}
	else if (right && !left)
	{
		printf("4");
		return right;
	}
	return root;
}

// BinaNode *findCommonAncestor(BinaNode *root, BinaNode *p, BinaNode *q)
// {
// 	if (root == NULL || root == p || root == q)
// 	{
// 		printf("1");
// 		return root;
// 	}

// 	BinaNode *leftLCA = findCommonAncestor(root->LeftChild, p, q);
// 	BinaNode *rightLCA = findCommonAncestor(root->RightChild, p, q);
// 	if (leftLCA == NULL)
// 	{
// 		printf("2");
// 		return rightLCA;
// 	}

// 	else if (rightLCA == NULL)
// 	{
// 		printf("3");
// 		return leftLCA;
// 	}
// 	else
// 	{
// 		printf("4");
// 		return root;
// 	}
// }

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
	BinaNode *nodeP, *nodeQ, *root;
	BinaTree tree;
	int strLen;
	strLen = initStr(inStr, postStr, nodeP, nodeQ);
	tree = creatBinaTree(inStr, postStr, strLen);
	root = findCommonAncestor(tree, nodeP, nodeQ);
	// printf("1");
	printf("%c", root->data);
	// if (root == NULL)
	// {
	// 	printf("NULL");
	// }
	// else
	// {
	// 	printf("%c", root->data);
	// }

	// preOrder(tree);
	return 0;
}
