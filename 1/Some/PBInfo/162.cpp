#include<iostream>

using namespace std;

int main()
{
	int v[17],aux,n,i,j,ul;
	cin>>n;
	for(i=1;i<=n;i++)
	{
	cin>>v[i];
	cout<<v[i]<<" ";
	}
	cout<<"\n";
	for(i=1;i<n;i++){
		ul=v[1];
		for(j=1;j<n;j++)
		{
		v[j]=v[j+1];
		cout<<v[j]<<" ";
		}
		v[n]=ul;
		cout<<v[n]<<"\n";
	}
	return 0;
}
