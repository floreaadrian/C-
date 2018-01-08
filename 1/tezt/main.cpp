#include <iostream>
#include <vector>
#include <iterator>
using namespace std;
vector <int> v[10];
int main()
{
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        v[1].push_back(a);
    }
    for(auto it :: v[1])
        cout<<it;
    return 0;
}
