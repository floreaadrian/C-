#include<iostream>
using namespace std;
int main()
{
	int n,i,a=0,b=1,f;
	cin>>n;
	a=b=1;
	cout<<a<<" "<<b<<" ";
	for(i=3;i<=n;++i)
	{
		f=a+b;
		cout<<f<<" ";
		a=b;
		b=f;
	}
	cout<<b;
}
