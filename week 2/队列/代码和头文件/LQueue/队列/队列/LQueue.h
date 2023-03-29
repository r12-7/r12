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
//��ʽ���нṹ
typedef struct node
{
    int *data;                   //������ָ��
    struct node *next;            //ָ��ǰ������һ���
} Node;

typedef struct Lqueue
{
    Node *front;                   //��ͷ
    Node *rear;                    //��β
    size_t length;            //���г���
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
 *    @description : ��ʼ������
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void InitLQueue(LQueue* Q) {
   //Q = (LQueue*)malloc(sizeof(LQueue*));
    Q->front = NULL;
    Q->rear = Q->front;

};

/**
 *  @name        : void DestoryLQueue(LQueue *Q)
 *    @description : ���ٶ���
 *    @param         Q ����ָ��Q
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
 *    @description : �������Ƿ�Ϊ��
 *    @param         Q ����ָ��Q
 *    @return         : ��-TRUE; δ��-FALSE
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
 *    @description : �鿴��ͷԪ��
 *    @param         Q e ����ָ��Q,��������ָ��e
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ��
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
 *    @description : ȷ�����г���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
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
 *    @description : ��Ӳ���
 *    @param         Q ����ָ��Q,�������ָ��data
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : �����Ƿ�Ϊ��
 */
//��ѡ���Ϊp����ռ�
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
        Q->rear = pnewnode;//���¶�βָ��;
        return TRUE;
    }
};

/**
 *  @name        : Status DeLQueue(LQueue *Q)
 *    @description : ���Ӳ���
 *    @param         Q ����ָ��Q
 *    @return         : �ɹ�-TRUE; ʧ��-FALSE
 *  @notice      : None
 */
//��ѡ���Ϊp����ռ�
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
//main�����free(p);

/**
 *  @name        : void ClearLQueue(AQueue *Q)
 *    @description : ��ն���
 *    @param         Q ����ָ��Q
 *  @notice      : None
 */
void ClearLQueue(LQueue* Q) {
    while (!IsEmptyLQueue(Q)) {
        DeLQueue(Q);
    }
};

/**
 *  @name        : Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
 *    @description : ������������
 *    @param         Q ����ָ��Q����������ָ��foo
 *    @return         : None
 *  @notice      : None
 */
int TraverseLQueue(const LQueue *Q, void (*foo)(void *q));

/**
 *  @name        : void LPrint(void *q)
 *    @description : ��������
 *    @param         q ָ��q
 
 *  @notice      : None
 */
//д�������� 
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
