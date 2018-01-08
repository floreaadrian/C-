#include<iostream>

using namespace std;

int max(int a,int b){
    if (a>=b) return a;
    return b;
}

int main()
{
    int n,x,y,z;
    cin>>n;
    cin>>x>>y>>z;
    int nx=n/x,ny=n/y,nz=n/z;
    int m=max(nx,max(ny,nz));
    cout<<m;
    return 0;
}
