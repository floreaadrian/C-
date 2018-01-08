#include<iostream>

using namespace std;

int i,n,j,a[21][21],k=0;

void citire()
{
	cin>>n;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	cin>>a[i][j];
}

void bordare()
{
	int i,j;
	for(i=0;i<=n+1;++i) a[i][0]=a[i][n+1]=0;
	for(j=0;j<=n+1;++j) a[0][j]=a[n+1][j]=0;
}

int main()
{
	citire();
	bordare();
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		if(a[i][j]>a[i+1][j] && a[i][j]>a[i-1][j] && a[i][j]>a[i][j+1] && a[i][j]>a[i][j-1])
		k++;
	}
	cout<<k;
	return 0;
}
