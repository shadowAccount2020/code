#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> si;
    cout<<si.size()<<endl;
    for(int i=0; i<10; i++)
    {
        si.push(i);//push数据
    }
    cout<<si.size()<<endl;
    while(!si.empty())
    {
        cout<<si.top();//使用top
        si.pop();//pop数据
    }
    cout<<endl<<si.size()<<endl;
    return 0;
}
