#include <stdio.h>
#include <stdlib.h>

typedef struct _Node
{
    int data;
    struct _Node *next;
}Node;

//create list
Node * createList()
{
    Node *head = (Node *)malloc(sizeof (Node));
    head->next = NULL;
    return head;
}

//insert data
void insertList(Node *head,int d)
{
    Node *cur = (Node *)malloc(sizeof (Node));
    cur->data = d;
    cur->next = head->next;
    head->next = cur;
}

//traverse list
void traverseList(Node*head)
{
    head = head->next;
    while(head)
    {
        printf("%d\n",head->data);
        head = head->next;
    }
}

//count list
int countList(Node*head)
{
    head = head->next;
    int i = 0;
    while(head)
    {
        head = head->next;
        i++;
    }
    return i;
}

//search
Node *searchList(Node*head,int find)
{
    head = head->next;
    while(head)
    {
        if(head->data==find)
            break;
        head = head->next;
    }
    return head;
}

//delete
void deleteList(Node *head , Node *pfind)
{
    while(head -> next != pfind)
    {
        head = head -> next;
    }
    head -> next = pfind -> next;
    free(pfind);
}

//destory
void destoryList(Node *head)
{
    Node *t;
    while(head)
    {
        t=head->next;
        free(head);
        head = t;
    }
}

//reverse
void reverseList(Node *head)
{
    Node *h = head -> next;
    head->next = NULL;
    Node *t;
    while(h)
    {
            t = h->next;
            h->next = head ->next;
            head->next = h;
            h = t;
    }
}

//sort
void popSortList(Node *head)
{
    Node *p,*q;
    int len = countList(head);
    for(int i = 0;i< len-1;i++)
    {
        p = head -> next;
        q = p -> next;
        for(int j = 0;j<len-1-i;j++)
        {
            if(p->data > q->data)
            {
                p->data ^= q->data;
                q->data ^= p->data;
                p->data ^= q->data;
            }
            p = p->next;
            q = p->next;
        }
    }

}

int main()
{
    Node *head = createList();
    for(int i=0;i<10;++i)
    {
        insertList(head,i);
    }
    traverseList(head);
    printf("%d\n",countList(head));
    return 0;
}
