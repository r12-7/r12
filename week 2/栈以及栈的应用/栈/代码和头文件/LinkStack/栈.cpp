#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<malloc.h>

typedef struct StackNode {
	int data;
	struct StackNode* next;
}stacknode,*Linkstack;

Linkstack S;

int InitStack(Linkstack &S) {
	//构造一个空栈指针置顶为空 
	S = NULL;
	return 1;
}

//判断是否为空栈
int StackEmpty(Linkstack* S) {
	if (S == NULL) return 1;
	else
		return 0;
}

int Insert(Linkstack &S, int e) {
	StackNode* p;// = (StackNode*)malloc(sizeof(StackNode));
	p = new stacknode;

	p->data = e;
	p->next = S;
	S = p;
	return 1;

}

int  pop(Linkstack &S, int &e) {
	if (!S) return 0;
	stacknode* p ;
	p = S;
	S = S->next;
	free(p);
	return 1;
	
}

int GetTOP(Linkstack &S, int e) {
	if (!S) return 0;
	e = S->data;
	return e;
}

void Trave(Linkstack S) {
	stacknode* p = S;
	while (p) {

		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
int e,a;
int main() {
	Linkstack S;
	//S = (Linkstack*)malloc(sizeof(Linkstack));
	

	if (InitStack(S))
	{
		printf("链栈初始化成功!\n");
	}
	else
	{
		printf("链栈初始化失败!\n");
	}

	// 入栈
	int n;
	printf("请输入栈的元素个数:");
	scanf("%d", &n);
	for (int i = 0; i < n;)
	{
		int e;
		printf("请输入第%d个入栈的元素:", ++i);
		scanf("%d", &e);
		Insert(S, e);
	}
	printf("遍历栈:\n");
	Trave(S);

	// 出栈（取出两个元素）
	for (int i = 0; i < 2;)
	{
		
		pop(S, a);
		printf("第%d个出栈的元素:%d\n", ++i, a);
	}
	printf("遍历栈:\n");
	Trave(S);

	printf("栈顶元素是:%d\n", GetTOP(S,e));

	system("pause");

	return 0;
}
