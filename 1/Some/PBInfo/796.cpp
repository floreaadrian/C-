#include<iostream>
using namespace std;
int main()
{
	int a[51][51],n,i,m,j;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		cin>>a[i][j];
	}
	for(i=1;i<=n;++i)
	{
		a[i][m-1]=a[i][m];
	}
	for(i=1;i<=m;++i)
	{
		a[n-1][i]=a[n][i];
	}
	for(i=1;i<n;++i)
	{
		for(j=1;j<m;++j)
		{
			cout<<a[i][j]<<" ";
	    }
	    cout<<"\n";
	}
	return 0;
}
