#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
#define ElemType char
#define True 1

typedef struct Node
{
	ElemType data;
	struct Node *LeftChild;
	struct Node *RightChild;
} BinaNode, *BinaTree;

BinaTree creatBinaTree(void)
{
	BinaTree tree;
	ElemType temp;
	scanf("%c", &temp);
	if (temp != '#')
	{
		tree = (BinaTree)malloc(sizeof(BinaNode));
		tree->data = temp;
		tree->LeftChild = creatBinaTree();
		tree->RightChild = creatBinaTree();
		return tree;
	}
	else
	{
		return NULL;
	}
}

void proOrder(BinaTree tree)
{
	if (tree != NULL)
	{
		printf("%c ", tree->data);
		proOrder(tree->LeftChild);
		proOrder(tree->RightChild);
	}
}

void inOrder(BinaTree tree)
{
	if (tree != NULL)
	{
		inOrder(tree->LeftChild);
		printf("%c ", tree->data);
		inOrder(tree->RightChild);
	}
}

void postOrder(BinaTree tree)
{
	if (tree != NULL)
	{
		postOrder(tree->LeftChild);
		postOrder(tree->RightChild);
		printf("%c ", tree->data);
	}
}

int main(int argc, char const *argv[])
{
	BinaTree tree;
	tree = creatBinaTree();
	proOrder(tree);
	printf("\n");
	inOrder(tree);
	printf("\n");
	postOrder(tree);
	return 0;
}
