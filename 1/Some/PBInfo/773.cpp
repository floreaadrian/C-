#include<iostream>
#define mamt 1000001

using namespace std;

int max1=0,maxu=0,fr[mamt],n,m,i,j,a;

void citire()
{
	cin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
	cin>>a;
	fr[a]++;
    if(maxu<a && fr[a]>max1)
    {
    	maxu=a;
    	max1=fr[a];
	}
	}
}

int main()
{
	citire();
	cout<<maxu<<"\n";
	return 0;
}
