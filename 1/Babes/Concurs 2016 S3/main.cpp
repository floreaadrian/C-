//Subiectul 3
#include <iostream>

using namespace std;

void citire(int v[],int &n){
cin>>n;
    for(int i=0;i<n;++i)
        cin>>v[i];}

bool verf(int v[],int n){
    for(int i=0;i<n/2;++i)
        if(v[i]!=v[n-i-1]) return false;
    return true;
}

void perm(int v[],int n){
    for(int i=1;i<n;++i)
    {
        int aux=v[i-1];
        v[i-1]=v[i];
        v[i]=aux;
    }
}

void rez(int v[],int n){
    int k=n-1;
    int r=0;
    bool ok=false;
    while(k-- && !ok){
        if(verf(v,n))ok=true;
        else {
        r++;
        perm(v,n);
        }
    }
    if(ok)cout<<"Da\nNumarul necesar este: "<<r;
    else cout<<"Nu";
}

int main()
{
    int v[1005],n;
    citire(v,n);
    rez(v,n);
    return 0;
}
