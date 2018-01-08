#include<iostream>
using namespace std;

void citire()
{
	int n,v[101];
	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>v[i];
}
void afisare(int v[],int n)
{
	for(int i=1;i<=n;++i)
	cout<<v[i]<<" ";
}

int main()
{
	int v[101],i,n;
	citire();
	cout<<n;
	afisare(v,n);
}
