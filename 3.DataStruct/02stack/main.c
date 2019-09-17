#include <stdio.h>
#include <stdlib.h>

typedef struct  stack
{
    int len;
    int top;
    char *_space;
}stack;

void initStack(stack *s , int size)
{
    s->len = size;
    s->top = 0;
    s->_space = (char *)malloc(size);
}

int isEmpty(stack *s)
{
    return s->top == 0;
}

int isFull(stack *s)
{
    return s->top == s->len;
}

void push(stack *s,char ch)
{
    s->_space[s->top++] = ch;
}

char pop(stack *s)
{
    return s->_space[--s->top];
}

void resetStack(stack *s)
{
    s->top = 0;
}

void clearStack(stack *s)
{
    free(s->_space);
}


int main()
{
    stack s;
    initStack(&s,27);
    for(char i = 'A'; i != 'Z'+1; ++i)
    {
        push(&s,i);
    }
    while(!isEmpty(&s))
    {
            char c = pop(&s);
            printf("%c\n",c);
    }
    return 0;
}
