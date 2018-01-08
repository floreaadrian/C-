#include<iostream>

using namespace std;

int main()
{
	int i,n;
	long f,p,a;
	cin>>n;
	if(n==1)
	cout<<1;
	else
	{
	p=a=1;
	cout<<a<<" "<<p<<" ";
	for(i=3;i<=n;i++)
	{
	f=p+a;
	cout<<f<<" ";
	a=p;
	p=f;
	}
	}
	return 0;
}
