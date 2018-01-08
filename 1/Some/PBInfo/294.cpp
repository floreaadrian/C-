#include<iostream>
using namespace std;
int main()
{
	int v[1001],i,j,n,og=0;
	cin>>n;
	for(i=1;i<=n;++i)
	cin>>v[i];
	while(v[1])
	{
		og=og*10+v[1]%10;
		v[1]/=10;
	}
	for(i=2;i<=n;++i)
	{
		if(v[i]==og)
		{
			cout<<"DA";
			return 0;
		}
	}
	cout<<"NU";
}
