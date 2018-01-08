#include<iostream>
using namespace std;
int main()
{
	int s=0,i,n,v[201],c=0,co=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		s+=v[i];
	}co=s/n;
	for(i=1;i<=n;++i)
	{
		if(v[i]>co)
		c++;
	}
	cout<<c;
}
