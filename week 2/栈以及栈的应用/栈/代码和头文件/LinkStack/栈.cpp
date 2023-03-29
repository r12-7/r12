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
	//����һ����ջָ���ö�Ϊ�� 
	S = NULL;
	return 1;
}

//�ж��Ƿ�Ϊ��ջ
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
		printf("��ջ��ʼ���ɹ�!\n");
	}
	else
	{
		printf("��ջ��ʼ��ʧ��!\n");
	}

	// ��ջ
	int n;
	printf("������ջ��Ԫ�ظ���:");
	scanf("%d", &n);
	for (int i = 0; i < n;)
	{
		int e;
		printf("�������%d����ջ��Ԫ��:", ++i);
		scanf("%d", &e);
		Insert(S, e);
	}
	printf("����ջ:\n");
	Trave(S);

	// ��ջ��ȡ������Ԫ�أ�
	for (int i = 0; i < 2;)
	{
		
		pop(S, a);
		printf("��%d����ջ��Ԫ��:%d\n", ++i, a);
	}
	printf("����ջ:\n");
	Trave(S);

	printf("ջ��Ԫ����:%d\n", GetTOP(S,e));

	system("pause");

	return 0;
}
