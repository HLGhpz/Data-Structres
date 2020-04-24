#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct Doublenode
{
	ElemType value;
	struct Doublenode *next, *prior;
} Doublenode, *DoubleList;

DoubleList creatList()
{
	int temp;
	Doublenode *head, *near, *s;
	head = near = (Doublenode *)malloc(sizeof(Doublenode));
	head->next = head;
	head->prior = head;
	while (1)
	{
		s = (Doublenode *)malloc(sizeof(Doublenode));
		scanf("%d", &temp);
		if(temp==0){
			break;
		}
		s->value = temp;
		s->prior = head->prior;
		near = head->prior;
		near->next = s;
		s->next = head;
		head->prior = s;
	}

	return head;
}

DoubleList sortList(DoubleList list)
{
	int t;
	Doublenode *p, *q;
	p = list->next; //ÅÅÐò
	while (p != list)
	{
		q = p->next;
		while (q != list)
		{
			if (p->value > q->value)
			{
				t = p->value;
				p->value = q->value;
				q->value = t;
			}
			q = q->next;
		}
		p = p->next;
	}
	return (list);
}

int main(int argc, char const *argv[])
{
	Doublenode *p, *q;
	p = sortList(creatList());
	sortList(p);
	q = p->next;
	while (q != p)
	{
		printf("%d ", q->value);
		q = q->next;
	}
	return 0;
}
