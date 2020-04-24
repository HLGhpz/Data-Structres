#include <stdio.h>
#include <stdlib.h>

#define stackSize 50
#define elemType int
#define FALSE 0
#define TRUE 1

typedef struct
{
	elemType elem[stackSize];
	int top;
} seqStack;

void initStack(seqStack *S)
{
	S->top = -1;
}

int push(seqStack *S, elemType x)
{
	if (S->top == stackSize)
	{
		return FALSE;
	}
	S->top++;
	S->elem[S->top] = x;
	return TRUE;
}

int pop(seqStack *S, elemType *x)
{
	if (S->top == -1)
	{
		return FALSE;
	}
	*x = S->elem[S->top];
	S->top--;
	return TRUE;
}

int conversion(int N, int conv)
{
	seqStack S;
	elemType x;
	initStack(&S);
	while (N > 0)
	{
		x = N % conv;
		push(&S, x);
		N = N / conv;
	}
	while (S.top != -1)
	{
		pop(&S, &x);
		// printf("x=%d\t", x);
		if(x<10){
			printf("%d", x);
		}else{
			printf("%c", x+55);
		}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	int number, conv;
	scanf("%d %d", &number, &conv);
	conversion(number, conv);
	return 0;
}
