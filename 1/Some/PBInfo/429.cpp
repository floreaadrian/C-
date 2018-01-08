#include<iostream>
using namespace std;
int main()
{
	int a,b,c=0,s=0,n1,n2;
	cin>>a>>b;
	n1=a;n2=b;
	while(a)
	{
		if(a%2==0)c++;
		a/=2;
	}
	while(b)
	{
		if(b%2==0)s++;
		b/=2;
	}
	if(c<s)cout<<n1;else cout<<n2;
}
