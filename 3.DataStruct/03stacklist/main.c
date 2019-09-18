#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    char ch;
    struct Node * nest;
}Node;

typedef struct stack
{
    Node * top;
}stack;

//初始化创建stack
void initStack(stack *s)
{
    s->top = (Node *)malloc(sizeof (Node));
    s->top->nest = NULL;
}

//判空
int isEmpty(stack *s)
{
    return s->top->nest == NULL;
}

//push
void pushStack(stack *s  , char ch)
{
    Node * node = (Node *)malloc(sizeof (Node));
    node->ch = ch;
    node->nest = s->top->nest;
    s->top->nest = node;
}

//pop
char popStack (stack *s)
{
     Node * node = s->top->nest->nest;
     char ch = s->top->nest->ch;
     free(s->top->nest);
     s->top->nest = node;
     return ch;
}

int main()
{
    stack s;
    initStack(&s);
    for(char i = 'A'; i != 'Z'+1; ++i)
    {
        pushStack(&s,i);
    }
    while(!isEmpty(&s))
    {
            char c = popStack(&s);
            printf("%c\n",c);
    }
    return 0;
}
