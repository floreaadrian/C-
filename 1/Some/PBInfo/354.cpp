#include<iostream>
using namespace std;
int main()
{
	int n,m=0,i,a;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a>m)m=a;
	}
	if(a>m)m=a;
	cout<<m;
}
