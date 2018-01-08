#include<iostream>
using namespace std;
int main()
{
	int v[100],n,i;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(v[i]%2==0)
		{
			i++;n++;
			v[i]=v[i-1]*2;
		}
	}
	for(i=1;i<=n;++i)
	cout<<v[i]<<" ";
}
