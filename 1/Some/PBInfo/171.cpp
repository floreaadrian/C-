#include<iostream>
using namespace std;
int main()
{
	int c,mi=0,n,i,a,p,k;
	cin>>n;
	cin>>a;p=a;
	while(p>9)
	{
		p/=10;
	}mi=p;k=a;
	for(i=2;i<=n;++i)
	{
		cin>>a;p=a;
		while(p>9)
	{
		p/=10;
	}
	if(p<mi)
	{
		k=a;mi=p;
	  }
	  else
	    if(p==mi && a>k)
	    {
		k=a;mi=p;
	    }
	}
	cout<<k;
}
