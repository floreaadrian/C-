#include<iostream>

using namespace std;

int main()
{
	int v[1001],i,n;
	cin>>n;
	for(i=1;i<=n;i++)
	cin>>v[i];
	for(i=1;i<=n;i++)
	if(v[i]%v[n]==0)
	cout<<v[i]<<" ";
	return 0;
}
