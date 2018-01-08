#include<iostream>
using namespace std;
int main()
{
	int v[201],c=0,s=0,i,n,m;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]!=0){
			c++;s+=v[i];
		}
	}
	m=s/c;
	for(i=1;i<=n;++i)
	{
		if(v[i]==0)
		v[i]=m;
		cout<<v[i]<<" ";
	}
}
