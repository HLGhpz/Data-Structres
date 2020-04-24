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
} seqStack;

void initStack(seqStack *S)
{
	S->top = -1;
}

int push(seqStack *S, elemType ch)
{
	if (S->top == stackSize)
	{
		return FALSE;
	}
	S->top++;
	S->elem[S->top] = ch;
	return TRUE;
}

int pop(seqStack *S, elemType ch)
{
	elemType temp;
	// printf("pop ch=%c\t", ch);
	if (S->top == -1)
	{
		return FALSE;
	}
	temp = S->elem[S->top];
	// printf("pop temp=%c\t", temp);
	if (temp == ch)
	{
		S->top--;
	}
	else
	{
		// printf("return false\n");
		return FALSE;
	}
	return TRUE;
}

int bracketMatch(void)
{
	seqStack S;
	elemType ch;
	elemType temp;
	int flag = 1;
	initStack(&S);
	while (1)
	{
		ch = getchar();
		// printf("ch = %c\t", ch);
		if (ch == '\n')
		{
			if (S.top != -1)
			{
				// printf("s.top!=-1\n");
				return FALSE;
			}
			return TRUE;
		}

		if (ch != '\n')
		{
			switch (ch)
			{
			case '(':
				push(&S, ch);
				break;
			case '{':
				push(&S, ch);
				break;
			case '[':
				push(&S, ch);
				break;
			case ')':
				temp = '(';
				flag = pop(&S, temp);
				break;
			case '}':
				temp = '{';
				flag = pop(&S, temp);
				break;
			case ']':
				temp = '[';
				flag = pop(&S, temp);
				break;
			default:
				break;
			}
			if (flag == FALSE)
			{
				// printf("flag==FALSE\n");
				return FALSE;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int flag;
	flag = bracketMatch();
	if (flag == 0)
	{
		printf("NO");
		return 0;
	}
	printf("YES");
	return 0;
}
