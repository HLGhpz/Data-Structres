#include <stdio.h>
#include <stdlib.h>

#define ElemType int

typedef struct Ploynode
{
	ElemType value;
	struct Ploynode *next;
} Ploynode, *Ploylist;

Ploylist creatList();
Ploylist mergeList(Ploylist listA, Ploylist listB);
Ploylist removeSome(Ploylist list);

int main(int argc, char const *argv[])
{
	Ploynode *p, *q;
	p = creatList();
	q = creatList();
	removeSome(mergeList(p, q));
	return 0;
}

Ploylist creatList()
{
	int number; //链表长度
	int i;		//计算
	Ploynode *head, *near, *s;
	head = near = (Ploynode *)malloc(sizeof(Ploynode));
	scanf("%d", &number);
	for (i = 0; i < number; i++)
	{
		s = (Ploynode *)malloc(sizeof(Ploynode));
		scanf("%d", &s->value);
		near->next = s;
		near = s;
	}
	near->next = NULL;
	return head;
}

Ploylist mergeList(Ploylist listA, Ploylist listB)
{
	Ploynode *p, *q, *temp;
	Ploynode *head, *near, *s;
	head = near = (Ploynode *)malloc(sizeof(Ploynode));
	int flag = 0;
	p = listA->next;
	q = listB->next;
	if (p->value <= q->value)
	{
		flag = 1;
	}
	else
	{
		flag = 2;
	}
	while (p != NULL || q != NULL)
	{
		s = (Ploynode *)malloc(sizeof(Ploynode));
		if (p != NULL && q != NULL)
		{
			if (p->value == q->value)
			{
				s->value = p->value;
				p = p->next;
				q = q->next;
			}
			else if (p->value > q->value)
			{
				s->value = q->value;
				q = q->next;
			}
			else
			{
				s->value = p->value;
				p = p->next;
			}
		}
		else if (p == NULL)
		{
			s->value = q->value;
			q = q->next;
		}
		else
		{
			s->value = p->value;
			p = p->next;
		}
		near->next = s;
		near=s;
	}
	near->next = NULL;
	return head;
}

Ploylist removeSome(Ploylist list){
	Ploynode *p, *q;
	p = list->next;
	q = p->next;
	while (q!=NULL)
	{
		if(p->value == q->value){
			p->next = q->next;
			free(q);
			q = p->next;
		}else{
			p = p->next;
			q = q->next;
		}
	}
	q = list->next;
	while (q!=NULL)
	{
		printf("%d ", q->value);
		q = q->next;
	}
	return list;
}