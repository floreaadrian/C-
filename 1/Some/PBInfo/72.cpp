#include<iostream>
using namespace std;

int sume(int v[101],int n,int a,int b)
{
	int s=0;
	for(int i=1;i<a;++i)s+=v[i];
	for(int i=b+1;i<=n;++i)s+=v[i];
	return s;
}
int main()
{
	int v[101],j,n,i;
	cin>>n>>i>>j;
	for(int k=1;k<=n;++k)
	{
		cin>>v[k];
	}
	cout<<sume(v,n,i,j);
}
