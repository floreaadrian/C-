#include<iostream>
using namespace std;
int main()
{
	int x,y,a[1001],b[1001],i,j;
	bool ok;
	cin>>x;
	for(i=1;i<=x;++i)
	cin>>a[i];
	cin>>y;
	for(i=1;i<=y;++i)
	cin>>b[i];
	for(i=1;i<=y;i++)
	{
		ok=true;j=1;
		while(ok && j<=x)
		{
			if(b[i]==a[j])ok=false;
			j++;
		}
		if(ok)cout<<0<<" ";else cout<<1<<" ";
	}
}
