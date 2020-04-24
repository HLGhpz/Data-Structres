#include <stdio.h>

#define ElemType char
#define Maxsize 2000
#define True 1
#define Flase -1

typedef struct
{
	ElemType elem[Maxsize];
	int top;
} seqStack;

int initStack(seqStack *S)
{
	ElemType ch;
	int temp = 0;
	S->top = -1;
	while (True)
	{
		ch = getchar();

		if (ch == '&')
		{
			while (ch != '@')
			{
				ch = getchar();
				if (ch == '@')
				{
					break;
				}
				else if (ch == S->elem[S->top])
				{
					temp++;
					S->top--;
				}else{
					printf("no");
					return 0;
				}
			}
			if (temp == 0 || S->top != -1)
			{
				printf("no");
			}
			else
			{
				printf("%d", temp);
			}
			return 0;
		}
		S->top++;
		S->elem[S->top] = ch;
	}
}

int main(int argc, char const *argv[])
{
	seqStack S;
	initStack(&S);
	return 0;
}
