#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[101][101],n,m,i,j,c=0,k=1,v[101];
	bool ok=true;
	cin>>n>>m;
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		cin>>a[i][j];
	}
	for(i=1;i<=n;++i)
	for(j=1;j<=m;++j)
	{
		if(a[i][j+1]!=a[i+1][j] && a[i+1][j]!=a[i-1][j] && a[i-1][j]!=a[i][j-1] && a[i][j-1]!=)
		c++;
	}
	cout<<c;
}
