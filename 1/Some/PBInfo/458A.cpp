#include<iostream>
using namespace std;
int main()
{
	int n,i,j;
	string a,b;
	cin>>n>>a>>b;
	for(i=1;i<=n/2;++i)
	{
	for(j=1;j<=n/2;++j)
	{
		cout<<a;
		cout<<b;
	}
	cout<<a<<"\n";
	for(j=1;j<=n/2;++j)
	{
		cout<<b;
		cout<<a;
	}
	cout<<b;
	cout<<"\n";
    }
    for(j=1;j<=n/2;++j)
	{
		cout<<a;
		cout<<b;
	}
	cout<<a<<"\n";
	return 0;
}
