#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string a,b;
	int n,i,j,i1,j1;
	cin>>n;
	cin>>a>>b;
	for(i=1;i<=n/2;++i)
	{
		for(j=1;j<=n/2;++j)
		{
			cout<<a<<b;
		}cout<<"\n";
		for(j=1;j<=n/2;++j)
		{
			cout<<b<<a;
		}cout<<"\n";
	}
}
