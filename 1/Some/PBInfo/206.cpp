#include<iostream>
using namespace std;
int main()
{
	int ma[25][25],m,n,i,j,a,b;
	cin>>n>>a>>b;
	for(i=1;i<=n;++i)
	for(j=1;j<=n;++j)
	{
		if(i==a || j==b)
		ma[i][j]=0;else
		if(i<a && j<b)
		ma[i][j]=1;else
		if(i>a && j<b)
		ma[i][j]=2;else
		if(i>a && j<b)
		ma[i][j]=3;else
		if(i>a && j>b)
		ma[i][j]=4;
	}
	for(i=1;i<=n;++i)
	{
		for(j=1;j<=n;++j)
		cout<<ma[i][j]<<" ";
		cout<<"\n";
	}
}
