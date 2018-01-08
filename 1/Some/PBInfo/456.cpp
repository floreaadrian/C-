#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string a;
	int i,n,j;
	cin>>n;
	cin>>a;
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=i;++j)
		cout<<a;
		cout<<"\n";
	}
}
