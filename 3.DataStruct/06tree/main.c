#include <stdio.h>

typedef struct TreeNode
{
    int _data;                    //数据域
    struct TreeNode *_left;
    struct TreeNode *_right;//左指针域和右指针域
}TreeNode;

void PreOrder(TreeNode *b)
{
    if (b!=NULL)
    {
        printf("%c ",b->_data);
        PreOrder(b->_left);
        PreOrder(b->_right);
    }
}

void InOrder(TreeNode *b)
{
    if (b!=NULL)
    {
        InOrder(b->_left);
        printf("%c ",b->_data);
        InOrder(b->_right);
    }
}

void PostOrder(TreeNode *b)
{
    if (b!=NULL)
    {
        PostOrder(b->_left);
        PostOrder(b->_right);
        printf("%c ",b->_data);
    }
}

int getTreeHeightByPostOrder(TreeNode *r)
{
    int lH,rH,maxH;
    if(r)
    {
        lH = getTreeHeightByPostOrder(r->_left);
        rH = getTreeHeightByPostOrder(r->_right);
        maxH = lH > rH ? lH : rH;
        return maxH + 1;
    }
    return 0;
}

int main()
{
    printf("Hello World!\n");
    return 0;
}
