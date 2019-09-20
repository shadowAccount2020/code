#include <queue>
#include <cstring>
#include <cstdio>
using namespace std;
//结构体
struct Node
{
    Node(int nri, char *pszName)
    {
        priority = nri;
        strcpy(szName, pszName);
    }
    char szName[20];
    int priority;
};
//结构体的比较方法 改写 operator()
class NodeCmp
{
public:
        bool operator()(const Node &na, const Node &nb)
    {
        if (na.priority != nb.priority)
            return na.priority > nb.priority;
        else
            return strcmp(na.szName, nb.szName) < 0;
    }
};
void PrintfNode(const Node &na)
{
    printf("%s %d\n", na.szName, na.priority);
}
int main()
{
    //优先级队列默认是使用 vector 作容器， 底层数据结构为堆。
    priority_queue<Node, vector<Node>, NodeCmp> a;
    //有 5 个人进入队列
    a.push(Node(5, "abc"));
    a.push(Node(3, "bac"));
    a.push(Node(1, "cba"));
    a.push(Node(5, "aaa"));
    //队头的 2 个人出队
    PrintfNode(a.top());
    a.pop();
    PrintfNode(a.top());
    a.pop();
    printf("--------------------\n");
    //再进入 3 个人
    a.push(Node(2, "bbb"));
    a.push(Node(2, "ccc"));
    a.push(Node(3, "aaa"));
    //所有人都依次出队
    while (!a.empty())
    {
        PrintfNode(a.top());
        a.pop();
    }
    //2 ccc 2 bbb 3 aaa 5abc 5aaa
   return 0;
}
