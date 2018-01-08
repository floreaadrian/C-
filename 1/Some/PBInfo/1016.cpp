#include<iostream>
using namespace std;
int fact(int n)
{
	int fa=1;
	for(int i=1;i<=n;++i)
	fa=fa*i;
	return fa;
}
int main()
{
	int n,s,k,p;
	cin>>n;
	p=n;
	if(n%2==0)
	{k=n/2;
	n/=2;
	}else {k=n/2-1;
	n=n/2+1;}
	s=(fact(p))/(fact(k));
	cout<<s;
	return 0;
}
