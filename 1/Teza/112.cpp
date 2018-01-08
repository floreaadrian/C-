#include<iostream>
using namespace std;
int main()
{
	int n,i,a,s=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;s+=a;
	}
	cout<<s%10;
}
