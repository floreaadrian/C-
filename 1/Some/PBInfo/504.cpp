#include<iostream>
using namespace std;
int main()
{
	int v[1001],i,j,n,aux;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	if(v[1]>v[n])
	{
		aux=v[n];
		v[n]=v[1];
		v[1]=aux;
	}
	for(i=2;i<n;++i)
	{
		if(v[1]>v[i] || v[i]>v[n])
		{
			cout<<"NU";
			return 0;
		}
	}
	cout<<"DA";
}
