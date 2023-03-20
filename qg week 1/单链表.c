#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>

struct node {
	int num;
	struct node* next;
}node;

//创建链表
struct node* creatlist() {
	struct node* headnode =(struct node*)malloc(sizeof(node));
	headnode->next = NULL;
	return headnode;
}

//创建结点
struct node* creatnode(int data) {
	struct node* newnode = (struct node*)malloc(sizeof(node));
	newnode->num = data;
	newnode->next = NULL;
	return newnode;
}

//打印
void printlist(struct node* headnode) {
	struct node* pmove = headnode->next;
	while (pmove) {
		printf("此结点的数为：%d", pmove->num);
		pmove = pmove->next;
		printf("\n");
	}
	printf("\n");
}

//头插法
void insert(struct node* headnode,int num) {
	//创建插入结点
	struct node* newnode = creatnode(num);
	newnode->next = headnode->next;
	headnode->next = newnode;
}

//删除
void delete(struct node* headnode,int data) {
	struct node* nownode = headnode->next;
	struct node* frontnode = headnode;
	if (nownode == NULL) {
		printf("链表为空");

	}
	else {
		while (nownode->num != data) {
			frontnode = nownode;
			nownode = frontnode->next;
			if (nownode == NULL) {
				printf("未找到");
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