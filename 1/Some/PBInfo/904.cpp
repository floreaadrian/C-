#include<iostream>
using namespace std;
int concat(int a,int b)
{
	int c=0,l=0,r=1,b1;
	b1=b;
	while(b>0)
	{
		c++;
		b=b/10;
	}
	for(int i=1;i<=c;++i)
	r=r*10;
	l=a*r+b1;
	return l;
}
int main()
{
	int n,a,b;
	cin>>a>>b;
	cout<<concat(a,b);
	return 0;
}
