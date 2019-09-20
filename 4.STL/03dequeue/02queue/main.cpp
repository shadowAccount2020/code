#include <iostream>
#include <queue>
using namespace std;
int main()
{
    queue<int> qi;
    cout<<qi.size()<<endl;
    for(int i=0; i<10; i++)
    {
        qi.push(i);
    }
    while(!qi.empty())
    {
        cout<<qi.front()<<" ";//ÓÃfront
        qi.pop();
    }
    cout<<endl<<qi.size()<<endl;
    return 0;
}
