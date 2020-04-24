#include <stdio.h>
#include <stdlib.h>

#define stackSize 50
#define elemType char
#define FALSE 0
#define TRUE 1

typedef struct
{
	elemType elem[stackSize];
	int top;
}seqStack;

void initStack(seqStack *S)
{
	S->top = -1;
}

int push(seqStack *S, elemType x)
{
	if(S->top == stackSize){
		return FALSE;
	}
	S->top++;
	S->elem[S->top] = x;
	return TRUE;
}

int pop(seqStack *S)
{
	// char temp;
	if (S->top == -1)
	{
		// return FALSE;
		return FALSE;
	}
	// temp = S->elem[S->top];
	S->top--;
	return TRUE;
}

int bracketMatch(void)
{
	seqStack S;
	initStack(&S);
	int count = 0;
	char ch;
	while (1)
	{
		ch = getchar();
		// printf("ch = %c\t", ch);
		if (ch=='@')
		{
			if (S.top!=-1)
			{
				return FALSE;
			}

			return count;
		}

		if (ch!='@')
		{
			if (ch=='(')
			{
				push(&S, ch);
			}else if (ch==')')
			{
				if(pop(&S) == 0){
					return FALSE;
				}
				count++;
			}
		}

	}
}

int main(int argc, char const *argv[])
{
	int count=0;
	count =	bracketMatch();
	if (count==0)
	{
		printf("no");
		return 0;
	}
	printf("%d", count);
	return 0;
}
