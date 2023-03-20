#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node* next;
}node;

//��������
struct node* creatlist() {
	struct node* headnode =(struct node*)malloc(sizeof(node));
	headnode->next = NULL;
	return headnode;
}

//�������
struct node* creatnode(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(node));
	newnode->num = data;
	newnode->next = NULL;
	return newnode;
}

//��ӡ
void printlist(struct node* headnode) {
	struct node* pmove = headnode->next;
	while (pmove) {
		printf("�˽�����Ϊ��%d", pmove->num);
		pmove = pmove->next;
		printf("\n");
	}
	printf("\n");
}

//ͷ�巨
void insert(struct node* headnode,int num) {
	//����������
	struct node* newnode = creatnode(num);
	newnode->next = headnode->next;
	headnode->next = newnode;
}

//ɾ��
void delete(struct node* headnode,int data) {
	struct node* nownode = headnode->next;
	struct node* frontnode = headnode;
	if (nownode == NULL) {
		printf("����Ϊ��");

	}
	else {
		while (nownode->num != data) {
			frontnode = nownode;
			nownode = frontnode->next;
			if (nownode == NULL) {
				printf("δ�ҵ�");
				return;
			}
		}
		frontnode->next = nownode->next;
		free(nownode);
	}
}


int main() {
	struct node* list = creatlist();
	insert(list, 1);
	insert(list, 555);
	printlist(list);
	delete(list, 1);
	printlist(list);
}