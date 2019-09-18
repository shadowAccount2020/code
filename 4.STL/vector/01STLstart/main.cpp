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
    //打印方式一：
//    vector<int>::iterator itr;
//    for(itr = vi.begin();itr!=vi.end();++itr)
//    {
//        cout << *itr << endl;
//    }

    //打印方式二：
    sort(vi.begin(),vi.end(),Compare());
        for(auto itr = vi.begin();itr!=vi.end();++itr)
        {
            cout << *itr << endl;
        }
    return 0;
}
