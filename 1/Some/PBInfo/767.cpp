#include<iostream>
using namespace std;
int main()
{
	int a[102][101],n,i,m,j,s=0,max;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		cin>>a[i][j];
	}
	for(i=1;i<=n;++i)
	{
		a[i][m+1]=a[i][1];
	}
	m++;
	for(i=1;i<=n;++i)
	{
		for(j=2;j<=m;++j)
		cout<<a[i][j]<<" ";
		cout<<"\n";
	}
}
