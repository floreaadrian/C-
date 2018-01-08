#include<iostream>
using namespace std;

void num(int n,int v[101])
{
	for(int i=1;i<n;++i)
	{
		if(v[i]<=v[0])
		v[i]=0;
	}
	v[0]=0;
}
int main()
{
	int v[101],j,n,i;
	cin>>n;
	for(i=0;i<n;++i)
	cin>>v[i];
	num(n,v);
	for(i=0;i<n;++i)
	cout<<v[i]<<" ";
}
