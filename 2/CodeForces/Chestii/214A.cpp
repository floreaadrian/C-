#include<iostream>
using namespace std;
int main()
{
	int n,m,i,j,c=0;
	cin>>n>>m;
	for(i=0;i<=1000;++i)
	for(j=0;j<=1000;++j)
	{
		if(i*i+j==n && j*j+i==m)
		c++;
	}
	cout<<c;
}
