#include <stdio.h>

typedef int ElemType;

//值节点--多个 
typedef struct Node
{
	ElemType data;//存储队列的元素值 
	struct Node* next;//存储下一个元素节点的地址 
}DataNode;

//头节点--1个 
typedef struct
{
	DataNode* front;//存储队头元素节点的地址 （队首指针） 
	DataNode* rear;//存储队尾元素节点的地址 （队尾指针）
}LinkQueue;

/*
空：q->front==NULL && q->rear==NULL
满：与链栈一样，链队一般不会满，不存在队满上溢情况
*/

/*
1.初始化
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
2.销毁
*/
void DestroyQueue(LinkQueue* q)
{
	int deQueue(LinkQueue * q, ElemType * e);
	ElemType m;

	while (q->front != NULL || q->rear != NULL)//非空
	{
		//出队
		deQueue(q, &m);
	}
	free(q);
}

/*
3.判断是否为空
若为空，返回1；
否则，返回0
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
4.进队
*/
void enQueue(LinkQueue* q, ElemType e)
{
	DataNode* t;
	//1.构造一个节点t，data域存储e，next域存储NULL
	t = (DataNode*)malloc(sizeof(DataNode));
	t->data = e;
	t->next = NULL;
	//2.添加 
	if (q->front != NULL || q->rear != NULL)//非空
	{
		/*队非空*/
		q->rear->next = t;
		q->rear = t;
	}
	else
	{
		/*队空 */
		q->front = t;
		q->rear = t;
	}
}

/*
5.出队
若队列非空，出队，返回1；
否则，提示，返回0
*/
int deQueue(LinkQueue* q, ElemType* e)
{
	DataNode* t;

	if (q->front != NULL || q->rear != NULL)//非空
	{
		//1.让t指向队头元素节点
		t = q->front;
		//2.把队头元素存储到*e中
		*e = t->data;  // 其实是q->front->data 
		//3.删除队头元素节点
		if (q->front->next == NULL)//只有1个元素
		{
			/*只有1个元素*/
			q->front = NULL;
			q->rear = NULL;
		}
		else
		{
			/*多于1个元素*/
			q->front = t->next;
		}
		//4.释放t所占的存储空间
		free(t);
		return 1;
	}
	else
	{
		printf("队空，不能出队！\n");
		return 0;
	}
}

/*
6.求链式队列的长度
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
	//1.构造一个节点t，让它指向队首元素front 
	t = (DataNode*)malloc(sizeof(DataNode));
	t = q->front;
	len = 1;
	while (t->next != NULL)
	{
		len++;
		t = t->next;
	}
	printf("队列长度为%d\n", len);

}
/*
7.输出
*/
void DispQueue(LinkQueue* q)
{
	DataNode* p;
	p = q->front;
	printf("队列元素为：");
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
	printf("出队元素：%d\n", *e);
	deQueue(&lq, e);
	printf("出队元素：%d\n", *e);


	printf("队列为空返回1，否则返回0：%d\n", QueueEmpty(&lq));

	DispQueue(&lq);
	lenghtLinkQueue(&lq);
	DestroyQueue(&lq); //销毁队列 

	return 1;
}