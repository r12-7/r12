#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<malloc.h>
#include<stdbool.h>
#include<stdlib.h>
#include"head.h"

typedef struct node
{
    void* data;                   //数据域指针
    struct node* next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node* front;                   //队头
    Node* rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

void InitLQueue1(LQueue* Q) {
    //Q = (LQueue*)malloc(sizeof(LQueue*));
    Q->front = NULL;
    Q->rear = Q->front;
}

void DestoryLQueue(LQueue* Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        //free(Q->front);
        Q->front = Q->rear;
    }
};

bool IsEmptyLQueue(const LQueue* Q) {
    if (Q->front == Q->rear) {
        return true;
    }
    else
        return false;

};

bool GetHeadLQueue(LQueue* Q, int* e) {
    if (IsEmptyLQueue(Q)) {
        return  false;
    }
    else {
        e = Q->front->next->data;
        printf("%d\n", e);
        return true;

    }
}

bool  LengthLQueue(LQueue* Q,int num) {
    Node* p;//=(Node*)malloc(sizeof(Node*));
    p = Q->front;
    while (p) {
        num++;
        p = p->next;
    }
    return true;
};

int EnLQueue(LQueue* Q, int* data, Node* pnewnode) {
    //Node* pnewnode = (Node*)malloc(sizeof(Node*));
    pnewnode->data = data;
    if (Q->front==NULL) {
       /* pnewnode->data = data;
        pnewnode->next = Q->front;
        Q->front = Q->rear = pnewnode;*/
        Q->front = pnewnode;
        Q->rear = pnewnode;
        return true;
    }
    else {
        
        Q->rear->next = pnewnode;
        Q->rear = pnewnode;//更新队尾指针;
        return true;
    }
};

int DeLQueue(LQueue* Q, Node* p) {
     p = (Node*)malloc(sizeof(Node*));
    if (IsEmptyLQueue(Q)) {
       // printf("queue is empty");
        return false;
    }
    else {
        p = Q->front;
        Q->front = p->next;
        if (p->next == NULL) {
            Q->front = Q->rear;
        }
        free(p);
        return true;

    }
}

 void ClearLQueue(LQueue * Q, Node* p){
     
        while (!IsEmptyLQueue(Q)) {
            DeLQueue(Q,p);
        }
  };

int LPrint(LQueue* Q) {
     Node* p = Q->front->next;
     while (p) {
         printf("%d ", p->data);
     }
 };

int flag;
int data;//指针数据域
int add;//入队数据
int length;//队列长度
void show() {
    LQueue* Q = (LQueue*)malloc(sizeof(LQueue*));
    InitLQueue1(Q);
    Node* p = (Node*)malloc(sizeof(Node*));
    Node* addnode = (Node*)malloc(sizeof(Node*));
    //初始化

   while (1) {

        while (1) {
            flag = 0;

            printf("You can do these function:\n");
            printf("1.Check whether the queue is empty or not;\n");
            printf("2.Get the number of the queue head;\n");
            printf("3.Add a number into the queue;\n");
            printf("4.Get a number out of the queue;\n");
            printf("5.Read all the node of the queue;\n");
            printf("6.Get the length of the queue;\n");
            printf("7.Delete the queue and quit;\n");
            printf("Now please give me the number to finish the function:\n");
            scanf("%d", &flag);
            while (getchar() != '\n');
            if (flag < 1 || flag>7)
            {
                system("cls");
                printf("Please give me the right number!\n");
                system("pause");
            }
            else
                break;
        }
        system("cls");
        switch (flag) {
        case(1):
            if (IsEmptyLQueue(Q))
                printf("The queue is empty now!You should add something!\n");
            else
                printf("The queue is not empty now.\n");
            break;
        case(2):
            if (GetHeadLQueue(Q, data))
                LPrint(data);
            else
                printf("The queue is empty now!You should add something!\n");
            break;
        case(3):
            printf("please submit the number you want\n");
            scanf("&d", add);

            if (EnLQueue(Q, add, addnode))
                printf(" we have add it into the queue!\n");
            else
            {
                printf("The room is full!!!\n");
                exit(-1);
            }
            break;
        case(4):
            if (DeLQueue(Q,addnode))

                printf("We have get the node out of the queue.\n");
            else
                printf("The queue is empty now!\n");
        case(5):
            LPrint(Q);
            break;
        case(6):
            
            if (LengthLQueue(Q,length)) {
                printf("The length of the queue is %d.\n",length );
            }
            else
            {
                printf("There is some wrong in the queue!!!\n");
                exit(-1);
            }
            break;
        case(7):
            ClearLQueue(Q, p);
            printf("清除成功");
            exit(-1);
       
        }
      
   }
}

int a() {
    printf("good morning");
}

int main() {
    
    show();
    
}