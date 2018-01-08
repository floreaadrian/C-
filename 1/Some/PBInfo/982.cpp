#include<iostream>
#include<math.h>

using namespace std;

int main()
{
	int n,k,a,s,i,c,p;
	cin>>n>>k;
	c=0;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		s=a;
		while(s%k==0)
		s/=k;
		if(s==0)
		c++;
	}
	cout<<c;
	return 0;
}
