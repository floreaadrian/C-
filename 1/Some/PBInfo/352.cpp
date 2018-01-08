#include<iostream>
using namespace std;
int main()
{
    int nr=0,n,i,x,y,s;
    cin>>n;

   for(i=n/2;i>=1;i--)

   {
   s=0;x=i;

while(s<n) {s=s+x; x=x+1;}

if(n==s) {

cout<<i<<" ";

for(y=i+1;y<=x-1;y++)
cout<<y<<" ";
cout<<"\n"; }  
}
}
