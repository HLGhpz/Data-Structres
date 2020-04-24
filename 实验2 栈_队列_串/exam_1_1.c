#include <stdio.h>

#define ElemType int
#define Maxsize 200
#define True 1
#define False 0

typedef struct
{
	ElemType arrivalTime[Maxsize];
	ElemType spendTime[Maxsize];
	int len;
	int front;
	int rear;
} seqQueue;

void initQueue(seqQueue *Q)
{
	int i;
	int temp = 0;
	Q->rear = Q->front = 0;
	scanf("%d", &Q->len);
	for (i = 0; i < Q->len; i++)
	{
		scanf("%d", Q->arrivalTime[i]);
		scanf("%d", &Q->spendTime[i]);
		Q->rear++;
	}
}

float computationTime(int bankCounter, seqQueue Q)
{
	int i;
	int nowTime = 0;
	int time[20] = {0};
	int number = 0;
	float costTime = 0;
	int flag = 1;
	while (True)
	{
		for (i = 0; i < bankCounter; i++)
		{
			printf("hello world\n");
			if (Q.front == Q.rear)
			{
				printf("hello world\n");
				flag = 0;
				printf("%.2f\n", costTime / Q.len);
				return 0;
			}

			if (nowTime >= Q.arrivalTime[number] && time[i] <= 0)
			{
				costTime += nowTime - Q.arrivalTime[number];
				time[i] = Q.spendTime[Q.front];
				Q.front++;
				number++;
			}
			time[i]--;
		}
		nowTime++;
		i = 0;
	}
}

int main(int argc, char const *argv[])
{
	int bankCounter;
	int temp = 0;

	while (True)
	{
		scanf("%d", &temp);
		if(temp =='\n'){
			printf("error");
			return 0;
		}
		bankCounter = temp;
		seqQueue Q;
		initQueue(&Q);
		computationTime(bankCounter, Q);
	}

}
