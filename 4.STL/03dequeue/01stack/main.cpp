#include <iostream>
#include <stack>
using namespace std;
int main()
{
    stack<int> si;
    cout<<si.size()<<endl;
    for(int i=0; i<10; i++)
    {
        si.push(i);//push����
    }
    cout<<si.size()<<endl;
    while(!si.empty())
    {
        cout<<si.top();//ʹ��top
        si.pop();//pop����
    }
    cout<<endl<<si.size()<<endl;
    return 0;
}
