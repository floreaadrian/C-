#include<iostream>
using namespace std;
int main()
{
	int v[1001],i,n,s=0,ma=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]>ma)ma=v[i];
	}
	for(i=1;i<=n;++i)
	s+=ma-v[i];
	cout<<s;
}
