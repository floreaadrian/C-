#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int v[101],n,i;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
	}
	sort(v+1, v+n+1);
	for(i=1;i<=n;++i)
	{
		if(v[i]!=v[i+1]-1)
		{
			cout<<v[i]+1;
			return 0;
		}
	}
}
