#include <iostream>

using namespace std;

bool prim(int n)
{
    if(n==1)return false;
    if(n%2==0 && n>2) return false;
    int d=3;
    while(d*d<=n){
        if(n%d==0)return false;
        d+=2;
    }
    return true;
}

int fr[10];

int main()
{
    long long l;
    cin>>l;
    int nr=0;
    long long k=l;
    while(k){
        fr[k%10]++;
        k/=10;
        nr++;
    }
    int c=fr[2]+fr[3]+fr[5]+fr[7];
    cout<<c*nr<<"\n";
    cout<<prim(57);
    return 0;
}
