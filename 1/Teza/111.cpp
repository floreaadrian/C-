#include<iostream>
using namespace std;
int main()
{
	int a,b,i,n,s=0,l,c;
	bool ok=true;
	cin>>a>>b;l=a;
	while(a>9)
	{
	while(a>0)
	{
		s+=a%10;
		a/=10;
	}
	a=s;s=0;
    }
    for(i=l;i<=b;++i)
    {
    	s=0;c=i;
    while(c>9)
	{
	while(c>0)
	{
		s+=c%10;
		c/=10;
	}
	c=s;s=0;
    }
    if(c==a)
    cout<<i<<" ";
	}return 0;
}
