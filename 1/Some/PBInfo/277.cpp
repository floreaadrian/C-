#include<iostream>

using namespace std;

int main()
{
	int v[1001],n,i,s=0;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>v[i];
	for(i=2;i<n;i++)
	{
		if(v[i]>v[i-1] && v[i]>v[i+1])
		s+=v[i];
	}
	cout<<s;
}
