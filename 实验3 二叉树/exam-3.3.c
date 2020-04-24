#include <stdio.h>
#include <stdlib.h>

#define Maxsize 100
#define ElemType char
#define True 1

int LeafCount = 0;

typedef struct Node
{
	ElemType data;
	struct Node *LeftChild;
	struct Node *RightChild;
} BinaNode, *BinaTree;

BinaTree creatBinaTree(void);
void countLeafNode(BinaTree tree);
void changeTree(BinaTree tree);
void postOrder(BinaTree tree);

int main(int argc, char const *argv[])
{
	BinaTree tree;
	tree = creatBinaTree();
	countLeafNode(tree);
	printf("%d\n", LeafCount);
	changeTree(tree);
	postOrder(tree);
	return 0;
}

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

void countLeafNode(BinaTree tree)
{
	if (tree != NULL)
	{
		countLeafNode(tree->LeftChild);
		countLeafNode(tree->RightChild);
		if (tree->LeftChild == NULL && tree->RightChild == NULL)
		{
			LeafCount++;
		}
	}
}

void changeTree(BinaTree tree)
{
	BinaTree temp;
	if (tree != NULL)
	{
		temp = tree->RightChild;
		tree->RightChild = tree->LeftChild;
		tree->LeftChild = temp;
		changeTree(tree->LeftChild);
		changeTree(tree->RightChild);
	}
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
