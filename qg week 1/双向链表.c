#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdio.h>
#include<stdlib.h>
#define max 100;

typedef struct node {
	struct node* prior;
	int data;
	struct node* next;

}node;

//创建节点
node* creatnode(node* head) {
	head = (node*)malloc(sizeof(node));
	if (head == NULL) {
		printf("malloc error!/n");
		return NULL;
	}
	head->prior = NULL;
	head->next = NULL;
	head->data = rand() % max;
	return head;
}

//创建链表
node* creatlist(node* head, int length) {
	if (length == 1) {
		return (head = creatnode(head));
	}
	else {
		head = creatnode(head);
		node* p = head;
		for (int i = 1; i < length; i++) {
			node* body = (node*)malloc(sizeof(node));
			body->prior = NULL;
			body->next = NULL;

			body->data = rand() % max;
			p->next = body;
			body->prior = p;
			p = p->next;//指针后移一位;
		}
		/*p->next = head;
		head->prior = p;*/
	}
	return head;
}

//插入(在add前插入)
node* InSert(node* head, int add, int data) {
	node* temp = (node*)malloc(sizeof(node));
	if (temp == NULL) {
		printf("malloc error");
		return NULL;
	}
	else {
		temp->next = NULL;
		temp->prior = NULL;
		temp->data = data;
	}

	if (add == 1) {
		temp->next = head;
		head->prior = temp;
		head = temp;
	}
	else {
		node* body = head;
		for (int i = 1; i < add - 1; i++) {
			body = body->next;
		}
		//判断是否为链表尾
		if (body->next == NULL) {
			body->next = temp;
			temp->prior = body;
		}
		else {
			body->next->prior = temp;
			temp->next = body->next;
			body->next = temp;
			temp->prior = body;
		}
	}
	return head;

}

//删除
node* deletelist(node* head, int data) {
	node* temp = head;
	while (temp) {
		if (temp->data == data) {
			if (temp->prior == NULL) {
				head = temp->next;
				temp->next = NULL;
				free(temp);
				return head;

			}
			else if (temp->next == NULL) {
				temp->prior->next = NULL;
				free(temp);
				return head;
			}
			else {
				temp->prior->next = temp->next;
				temp->next->prior = temp->prior;
				free(temp);
				return head;
			}

		}
		temp = temp->next;
	}
	printf("cannot find %d\n", data);
	return head;

}

//打印
node* printlist(node* head) {
	node* p = head;
	while (p) {
		if (p->next == NULL) {
			printf("%d\n", p->data);
		}
		else {
			printf("%d->", p->data);
		}
		p = p->next;
	}
	return head;
}

int main() {
	node* head = NULL;
	head = creatlist(head, 10);
	printlist(head);
	InSert(head, 3, 666);
	printlist(head);
	deletelist(head, 666);
	printlist(head);
	deletelist(head, 34);
	
	printlist(head);
}