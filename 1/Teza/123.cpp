#include<iostream>
using namespace std;
int main()
{
	int a,b,n,i,s,c=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		s=0;
		cin>>a;
		b=a;
		while(a>0)
		{
			s=s+a%10;
			a/=10;
		}
		if(b%s==0)c++;
	}
	cout<<c;
}
