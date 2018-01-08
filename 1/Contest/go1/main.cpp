#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date.in");

int main()
{
    int n,a[1000],s;
    fin>>n>>s;
    for(int i=1;i<=n;++i)
        fin>>a[i];
    for(int i=1;i<=n;++i)
    if(a[i]+a[n-i+1]>=s){
        int k=a[i]
    }
    return 0;
}
