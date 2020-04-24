#include <stdio.h>
#include <stdlib.h>

typedef struct Polynode
{
	int coef, exp;
	struct Polynode *next;
} Polynode, *Polylist;

Polylist sortList(Polylist head);	//链表排序
Polylist createList();				//创建链表
Polylist addList(Polylist listA, Polylist listB);					//链表相加

int main(int argc, char const *argv[])
{
	Polynode *p, *q;
	p = createList();
	q = createList();
	addList(p, q);
	/* code */
	return 0;
}

Polylist sortList(Polylist head){
	Polynode *p, *q;
	int temp;			//排序时使用
	p = head->next;
	while (p != NULL)
	{
		q = p->next;
		while (q != NULL)
		{
			if (p->exp < q->exp)
			{
				temp = p->exp;
				p->exp = q->exp;
				q->exp = temp;
				temp = p->coef;
				p->coef = q->coef;
				q->coef = temp;
			}
			q = q->next;
		}
		p = p->next;
	}
	return head;
}

Polylist createList()
{
	Polynode *head, *rear, *s;
	Polynode *p;

	float c, e;		 //c为系数，e为指数
	int i;			 //用于计数
	int number;		 //链表长度
	rear = head = (Polynode *)malloc(sizeof(Polynode));
	scanf("%d", &number);
	for (i = 0; i < number; i++)
	{
		s = (Polynode *)malloc(sizeof(Polynode));
		scanf("%d", &s->coef);
		scanf("%d", &s->exp);
		rear->next = s;
		rear = s;
	}
	rear->next = NULL;

	// head = sortList(head);
	// p = head->next;
	// while (p!=NULL)
	// {
	// 	printf("%d->", p->exp);
	// 	p = p->next;
	// }
	return sortList(head);
}

Polylist addList(Polylist listA, Polylist listB){
	Polynode *p, *q, *tail, *temp;
	float sum;
	p = listA->next;
	q = listB->next;

}