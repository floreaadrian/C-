#include<iostream>
using namespace std;
int main()
{
	long v[100000],n,c=0,i;
	cin>>n;
	while(n>0)
	{
		c++;
		v[c]=n;
		n/=2;
	}
	for(i=c;i>=1;--i)
	cout<<v[i]<<" ";
}
