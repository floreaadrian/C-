#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	cout<<"{";
	for(i=1;i<=n;++i)
		for(j=1;j<=m;++j)
		cout<<"("<<i<<","<<j<<"),";
	cout<<"}";
}
