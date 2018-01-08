#include<iostream>
using namespace std;
int main()
{
	int v[1001],i,n,i_in,i_ul,s=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]%2!=0)
		{
			i_ul=i;
		}
	}
	for(i=1;i<=n;++i)
	{
		if(v[i]%2!=0)
		{
			i_in=i;
			break;
		}
	}
	for(i=i_in;i<=i_ul;++i)
	{
		s+=v[i];
	}
	cout<<s;
}
