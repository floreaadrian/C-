#include<iostream>
using namespace std;
int main()
{
	int v[501],i,n,a[501],j,k=0;
	bool ok=true;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	for(i=1;i<=n;++i)
	{
		ok=false;
		for(j=1;j<=n;++j)
		{
			if(a[i]%a[j]==0)
			{
				ok=true;
			}
		}
	}
	if(ok)
	cout<<"DA";else
	cout<<"NU";
}
