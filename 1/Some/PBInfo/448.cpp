#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int n,a;
    float ma=0,s=0;
    cin>>n;
    for(int i = 1 ; i <= n ; ++ i)
    {
        cin>>a;
        s=s+a;
    }
    ma=s/n;
    cout<<fixed<<setprecision(2)<<ma;
    return 0;
}
