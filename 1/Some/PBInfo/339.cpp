#include<iostream>
using namespace std;
int main()
{
	int a,n,i,ul=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a%2==0)
		{
			ul=a;
		}
	}
	if(ul!=0)cout<<ul;
	else cout<<"IMPOSIBIL";
}
