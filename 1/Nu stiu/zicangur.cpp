#include<iostream>
using namespace std;
int main()
{
	int k,n,i,j,zi;
	cin>>n>>k;
	zi=k;j=k;
	for(i=2;i<=n;++i)
	{
		zi=zi*10+k;j=j+zi;
	}cout<<j;
	return 0;
}
