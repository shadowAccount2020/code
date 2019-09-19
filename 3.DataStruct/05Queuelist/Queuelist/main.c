#include <stdio.h>
#include <stdlib.h>
struct QNode
{
    int data;
    struct QNode * next;
};
//链式存储中， 只放两个头尾指针
struct Queue
{
    struct QNode *front;
    struct QNode *rear;
};

void initQueue(struct Queue * q)
{
    q->rear = q->front =
            (struct QNode*)malloc(sizeof(struct QNode));
    q->rear->next = NULL;
}
int isQueueEmpty(struct Queue * q)
{
          return q->rear == q->front;
}
void enQueue(struct Queue * q,int dat)
{
    struct QNode * cur =
            (struct QNode *)malloc(sizeof(struct QNode));
            cur->data = dat;
            cur->next = q->rear->next;
            q->rear->next = cur;
            q->rear = cur;
}
int deQueue(struct Queue * q)
{
    if(q->front->next == q->rear)
    {
        //只有一个元素
        int t = q->front->next->data;
        q->front->next = q->front->next->next;
        free(q->rear);
        q->rear = q->front;
        return t;
    }
    else
    {
        //有多个元素
        int t = q->front->next->data;
        struct QNode* pdel = q->front->next;
        q->front->next = q->front->next->next;
        free(pdel);
        return t;
    }
}
void clearQueue(struct Queue *q)
{
    struct QNode * t = q->front;
    struct QNode * cur;
    while(t)
    {
        cur = t->next;
        free(t);
        t = cur;
    }
    q->front = q->rear = NULL;
}
int main()
{
    struct Queue q;
    initQueue(&q);
    for(int i=0; i<10; i++)
    {
        enQueue(&q,i);
    }
    while(!isQueueEmpty(&q))
    {
        printf("%d\n",deQueue(&q));
    }
    clearQueue(&q);
    return 0;
}
