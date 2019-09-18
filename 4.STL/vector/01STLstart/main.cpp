#include <iostream>
#include<algorithm>
#include<functional>
#include<vector>

using namespace std;

class Compare
{
public:
    Compare() {}
    bool operator()(int x,int y)
    {
        return x<y;
    }
};

int main()
{
    vector<int> vi = {8,4,6,7,2,9,4,6,2,1,0};
    //    sort(vi.begin(),vi.end(),Compare());
    //打印方式一：
    //    vector<int>::iterator itr;
    //    for(itr = vi.begin();itr!=vi.end();++itr)
    //    {
    //        cout << *itr << endl;
    //    }

    //打印方式二：

    //    vi.insert(vi.end(),10);
    vi.push_back(10);
    vi.pop_back();
    //    vi.clear();

    for(auto itr = vi.begin();itr!=vi.end();++itr)
    {
        cout << *itr << endl;
    }


    int i = vi.back();
    cout << i << endl;

    cout << vi.size() << endl; //11
    cout << vi.capacity() << endl;//22

    vi.push_back(10);
    cout << vi.size() << endl;//12
    cout << vi.capacity() << endl;//22

    return 0;
}
