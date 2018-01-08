#include<iostream>
using namespace std;
int main()
{
	int v[1000],i,n,aux;
	cin>>n;
	for(i=1;i<=n;++i)
	cin>>v[i];
	for(i=1;i<=n/2;++i)
	{
		aux=v[i];
		v[i]=v[n-i];
		v[n-i]=aux;
	}
	for(i=1;i<=n;++i)
	cout<<v[i]<<" ";
	return 0;
}
