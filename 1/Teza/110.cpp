#include<iostream>
using namespace std;
int a,b,aux,s,t,f;
int main()
{
cin>>a;
cin>>b;
if(a>b) 
{
aux=a;a=b;b=aux;
}
s=t=1;
f=s+t;
while(f<b)
{
s=t;t=f;f=s+t;
}

if(f>b) cout<<"Da";

else if(t==a) cout<<"NU";
return 0;
}
