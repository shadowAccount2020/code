#include <stdio.h>
#include<stdlib.h>
//front最开始指向空白待插入位置，rear指向有内容的待出队的位置
typedef struct _Queue
{
    char *_space;
    int _len;
    int _rear;
    int _front;
}Queue;

void initQueue(Queue *q,int size)
{
    q->_len = size;
    q->_space = (char *)malloc(sizeof(q->_len));
    q->_rear = q->_front = 0;
}

int isEmpty(Queue *q)
{
    return q->_front ==  q->_rear;
}

int isFull(Queue *q)
{
    return (q->_rear +1)%q->_len == q->_front;
}

void enQueue(Queue *q,char ch)
{
    q->_space[q->_rear] =ch;
    q->_rear = ++q->_rear %q->_len;
}

char deQueue(Queue *q)
{
    char ch = q->_space[q->_front];
    q->_front = ++q->_front %q->_len;
    return ch;
}

int main()
{
    Queue q;
    initQueue(&q,27);
    for(char i = 'A'; i < 'Z'+1; ++i)
    {
        enQueue(&q,i);
    }
    while(!isEmpty(&q))
    {
            char c = deQueue(&q);
            printf("%c\n",c);
    }
    return 0;
}
