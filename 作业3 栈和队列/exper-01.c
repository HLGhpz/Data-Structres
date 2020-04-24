#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 50
#define elemType int

typedef struct
{
	elemType element[MAXSIZE];
	int front;
	int rear;
} seqQueue;

void initQueue(seqQueue *Q)
{
	Q->front = Q->rear = 0;
}

int deleteQueue(seqQueue *Q, elemType* x)
{
	if(Q->front==Q->rear){
		return 0;
	}
	*x = Q->element[Q->front];
	Q->front = (Q->front+1)%MAXSIZE;
	return 1;
}

int enterQueue(seqQueue *Q, elemType x)
{
	if ((Q->rear + 1) % MAXSIZE == Q->front)
	{
		return 0;
	}
		Q->element[Q->rear] = x;
		Q->rear = (Q->rear + 1) % MAXSIZE;
		return 1;
}

void getHead(seqQueue Q, elemType *x){
	*x = Q.element[Q.front];
}

int isEmpty(seqQueue Q){
	return Q.rear == Q.front;
}

void yangHuiTriangle(int count)
{
	int i, n;
	elemType temp, x;
	seqQueue Q;
	initQueue(&Q);
	enterQueue(&Q, 1);
	for (n = 2; n <= count; n++)
	{
		enterQueue(&Q, 1);
		for (i = 1; i <= n-2; i++)
		{
			deleteQueue(&Q, &temp);
			printf("%d ", temp);
			getHead(Q, &x);
			temp += x;
			enterQueue(&Q, temp);
		}
		deleteQueue(&Q, &x);
		printf("%d", x);
		printf("\n");
		enterQueue(&Q, 1);
	}

	while (!isEmpty(Q))
	{
		deleteQueue(&Q, &x);
		printf("%d ", x);
	}
}


int main(int argc, char const *argv[])
{
	int count=0;
	scanf("%d", &count);
	yangHuiTriangle(count);
	return 0;
}
