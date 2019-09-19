#include <iostream>
#include<list>

using namespace std;

int main()
{
    list<int> li = {1,4,6,3,8,4,9,5};


    li.emplace(li.begin());

    cout << li.front() << endl;
    cout << li.back() << endl;

    for(auto itr = li.begin();itr != li.end();++itr)
    {
        cout << *itr << endl;
    }
    return 0;
}
