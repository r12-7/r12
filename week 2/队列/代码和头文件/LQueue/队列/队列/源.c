#include <stdio.h>

typedef int ElemType;

//ֵ�ڵ�--��� 
typedef struct Node
{
	ElemType data;//�洢���е�Ԫ��ֵ 
	struct Node* next;//�洢��һ��Ԫ�ؽڵ�ĵ�ַ 
}DataNode;

//ͷ�ڵ�--1�� 
typedef struct
{
	DataNode* front;//�洢��ͷԪ�ؽڵ�ĵ�ַ ������ָ�룩 
	DataNode* rear;//�洢��βԪ�ؽڵ�ĵ�ַ ����βָ�룩
}LinkQueue;

/*
�գ�q->front==NULL && q->rear==NULL
��������ջһ��������һ�㲻�����������ڶ����������
*/

/*
1.��ʼ��
*/
LinkQueue* InitQueue()
{
	LinkQueue* q;
	q = (LinkQueue*)malloc(sizeof(LinkQueue));
	q->front = NULL;
	q->rear = NULL;
	return q;
}

/*
2.����
*/
void DestroyQueue(LinkQueue* q)
{
	int deQueue(LinkQueue * q, ElemType * e);
	ElemType m;

	while (q->front != NULL || q->rear != NULL)//�ǿ�
	{
		//����
		deQueue(q, &m);
	}
	free(q);
}

/*
3.�ж��Ƿ�Ϊ��
��Ϊ�գ�����1��
���򣬷���0
*/
int QueueEmpty(LinkQueue* q)
{
	if (q->front == NULL && q->rear == NULL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

/*
4.����
*/
void enQueue(LinkQueue* q, ElemType e)
{
	DataNode* t;
	//1.����һ���ڵ�t��data��洢e��next��洢NULL
	t = (DataNode*)malloc(sizeof(DataNode));
	t->data = e;
	t->next = NULL;
	//2.��� 
	if (q->front != NULL || q->rear != NULL)//�ǿ�
	{
		/*�ӷǿ�*/
		q->rear->next = t;
		q->rear = t;
	}
	else
	{
		/*�ӿ� */
		q->front = t;
		q->rear = t;
	}
}

/*
5.����
�����зǿգ����ӣ�����1��
������ʾ������0
*/
int deQueue(LinkQueue* q, ElemType* e)
{
	DataNode* t;

	if (q->front != NULL || q->rear != NULL)//�ǿ�
	{
		//1.��tָ���ͷԪ�ؽڵ�
		t = q->front;
		//2.�Ѷ�ͷԪ�ش洢��*e��
		*e = t->data;  // ��ʵ��q->front->data 
		//3.ɾ����ͷԪ�ؽڵ�
		if (q->front->next == NULL)//ֻ��1��Ԫ��
		{
			/*ֻ��1��Ԫ��*/
			q->front = NULL;
			q->rear = NULL;
		}
		else
		{
			/*����1��Ԫ��*/
			q->front = t->next;
		}
		//4.�ͷ�t��ռ�Ĵ洢�ռ�
		free(t);
		return 1;
	}
	else
	{
		printf("�ӿգ����ܳ��ӣ�\n");
		return 0;
	}
}

/*
6.����ʽ���еĳ���
*/
int lenghtLinkQueue(LinkQueue* q)
{
	int len;
	if (QueueEmpty(&q))
	{
		len = 0;
		return len;
	}
	DataNode* t;
	//1.����һ���ڵ�t������ָ�����Ԫ��front 
	t = (DataNode*)malloc(sizeof(DataNode));
	t = q->front;
	len = 1;
	while (t->next != NULL)
	{
		len++;
		t = t->next;
	}
	printf("���г���Ϊ%d\n", len);

}
/*
7.���
*/
void DispQueue(LinkQueue* q)
{
	DataNode* p;
	p = q->front;
	printf("����Ԫ��Ϊ��");
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

int main()
{
	LinkQueue lq;
	lq = *InitQueue();

	enQueue(&lq, 1);
	enQueue(&lq, 2);
	enQueue(&lq, 3);
	enQueue(&lq, 4);
	enQueue(&lq, 5);
	enQueue(&lq, 6);
	enQueue(&lq, 7);
	enQueue(&lq, 8);
	enQueue(&lq, 9);
	DispQueue(&lq);
	lenghtLinkQueue(&lq);

	ElemType* e;
	e = (ElemType*)malloc(sizeof(ElemType));
	deQueue(&lq, e);
	printf("����Ԫ�أ�%d\n", *e);
	deQueue(&lq, e);
	printf("����Ԫ�أ�%d\n", *e);


	printf("����Ϊ�շ���1�����򷵻�0��%d\n", QueueEmpty(&lq));

	DispQueue(&lq);
	lenghtLinkQueue(&lq);
	DestroyQueue(&lq); //���ٶ��� 

	return 1;
}