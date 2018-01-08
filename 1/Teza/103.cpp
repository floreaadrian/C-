#include<iostream>
using namespace std;
int fr[4];
int main()
{
	int a,n,i;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		fr[a]++;
	}
	for(i=1;i<=3;++i)
	{
		while(fr[i])
		{
			cout<<i<<" ";
			fr[i]--;
		}
	}
}
