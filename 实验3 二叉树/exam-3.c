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
		tree->data = temp;
		return tree;
	}
}

void proOrder(BinaTree tree)
{
	printf("test0\t");
	if (tree->data != '#')
	{
		printf("test1\t");
		printf("%c ", tree->data);
		proOrder(tree->LeftChild);
		proOrder(tree->RightChild);
	}
	printf("test2\t");
}

int main(int argc, char const *argv[])
{
	BinaTree tree;
	tree = creatBinaTree();
	printf("test4\t");
	proOrder(tree);
	return 0;
}
