/***************************************************************************************
 *    File Name                :    LQueue.h
 *    CopyRight                :
 *
 *    SYSTEM                    :   Mac OS
 *    Create Data                :    2020.4.2
 *    Author/Corportation        :   Chuan Shi
 *
 *
 *--------------------------------Revision History--------------------------------------
 *    No    version        Data            Revised By            Item            Description
 *
 *
 ***************************************************************************************/

/**************************************************************
 *    Multi-Include-Prevent Section
 **************************************************************/
#ifndef LQUEUE_H_INCLUDED
#define LQUEUE_H_INCLUDED

/**************************************************************
 *    Struct Define Section
 **************************************************************/
//链式队列结构
typedef struct node
{
    int *data;                   //数据域指针
    struct node *next;            //指向当前结点的下一结点
} Node;

typedef struct Lqueue
{
    Node *front;                   //队头
    Node *rear;                    //队尾
    size_t length;            //队列长度
} LQueue;

typedef enum
{
    FALSE=0, TRUE=1
} Status;
char type;					
char datatype[30];			

/**************************************************************
 *    Prototype Declare Section
 **************************************************************/


/**
 *  @name        : void InitLQueue(LQueue *Q)
 *    @description : 初始化队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
   //Q = (LQueue*)malloc(sizeof(LQueue*));
    Q->front = NULL;
    Q->rear = Q->front;

};

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : 销毁队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void DestoryLQueue(LQueue* Q) {
    while (Q->front) {
        Q->rear = Q->front->next;
        //free(Q->front);
        Q->front = Q->rear;
    }
};

/**
 *  @name        : Status IsEmptyLQueue(const LQueue *Q)
 *    @description : 检查队列是否为空
 *    @param         Q 队列指针Q
 *    @return         : 空-TRUE; 未空-FALSE
 *  @notice      : None
 */
Status IsEmptyLQueue(const LQueue* Q) {
    if (Q->front == Q->rear) {
        return TRUE;
    }
    else
        return FALSE;
    
};

/**
 *  @name        : Status GetHeadLQueue(LQueue *Q, void *e)
 *    @description : 查看队头元素
 *    @param         Q e 队列指针Q,返回数据指针e
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否空
 */
int GetHeadLQueue(LQueue* Q, int* e) {
    if (IsEmptyLQueue(Q)) {
        return  FALSE;
         }
    else {
        e = Q->front->next->data;
       
        return TRUE;
        
    }

};

/**
 *  @name        : int LengthLQueue(LQueue *Q)
 *    @description : 确定队列长度
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
int  LengthLQueue(LQueue* Q) {
    Node* p;//=(Node*)malloc(sizeof(Node*));
    p = Q->front;
    int num=0;
    while (p) {
        num++;
        p = p->next;
    }
    return TRUE;
};

/**
 *  @name        : Status EnLQueue(LQueue *Q, void *data)
 *    @description : 入队操作
 *    @param         Q 队列指针Q,入队数据指针data
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : 队列是否为空
 */
//在选择后为p分配空间
int EnLQueue(LQueue* Q, int* data,Node* pnewnode) {
    //Node* pnewnode = (Node*)malloc(sizeof(Node*));
    if (IsEmptyLQueue(Q)) {
        pnewnode->data = data;
        pnewnode->next = Q->front;
        Q->front = Q->rear = pnewnode;
        return FALSE;
    }
    else {
        pnewnode->data = data;
        Q->rear->next = pnewnode;
        Q->rear = pnewnode;//更新队尾指针;
        return TRUE;
    }
};

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : 出队操作
 *    @param         Q 队列指针Q
 *    @return         : 成功-TRUE; 失败-FALSE
 *  @notice      : None
 */
//在选择后为p分配空间
int DeLQueue(LQueue* Q,Node* p) {
    //Node* p;// = (Node*)malloc(sizeof(Node*));
    if (IsEmptyLQueue(Q)) {
        //print("queue is empty");
        return FALSE;
    }
    else {
        p = Q->front;
        Q->front = p->next;
        if (p->next == NULL) {
            Q->front = Q->rear ;
        }
        //free(p);
        return TRUE;
        
    }
};
//main里加上free(p);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : 清空队列
 *    @param         Q 队列指针Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
    while (!IsEmptyLQueue(Q)) {
        DeLQueue(Q);
    }
};

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : 遍历函数操作
 *    @param         Q 队列指针Q，操作函数指针foo
 *    @return         : None
 *  @notice      : None
 */
int TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *    @description : 操作函数
 *    @param         q 指针q
 
 *  @notice      : None
 */
//写主函数里 
int LPrint(LQueue* Q) {
    Node* p = Q->front->next;
    while (p) {
      //  print("%d ", p->data);
    }
};

void printword() {
    printf("hello world");
}

/**************************************************************
 *    End-Multi-Include-Prevent Section
 **************************************************************/
#endif // LQUEUE_H_INCLUDED

;
