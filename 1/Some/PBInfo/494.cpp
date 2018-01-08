#include<iostream>
using namespace std;
int y[201];
int main()
{
	int x[201],s=0,n,i;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>x[i];
		y[i]-=x[i];
		s+=x[i];
	}
	for(i=1;i<=n;++i)
	y[i]+=s;
	for(i=1;i<=n;++i)
	cout<<y[i]<<" ";
}
