#include<iostream>
using namespace std;
int sumfactcif(int n)
{
	int s=0,c=1;
	while(n>0)
	{
		for(int i=1;i<=n%10;i++)
		{
		c=c*i;
		}
		s=s+c;
		c=1;
	    n=n/10;
	}
	return s;
}
int main()
{
	int n;cin>>n;
	cout<<sumfactcif(n);
	return 0;
}
