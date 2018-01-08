#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	int n,i,j;
	string a,b;
	cin>>n;
	cin>>a;
	cin>>b;
	for(i=1;i<=n;++i)
	cout<<a;
	cout<<"\n";
	for(i=2;i<n;++i)
	{
		cout<<a;
		for(j=1;j<n-1;++j)
		cout<<b;
		cout<<a;
		cout<<"\n";
	}
	for(i=1;i<=n;++i)
	cout<<a;
}
