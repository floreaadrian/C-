#include<iostream>
using namespace std;
int main()
{
	int a[101][101],b[101][101],i,j,n;
	cin>>n;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	cin>>a[i][j];
	for(j=1;j<=n;++j)
	{
		for(i=1;i<=n;++i)
		b[i][j]=a[i][j];
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++i)
		cout<<b[i][j]<<" ";
		cout<<"\n";
	}
}
