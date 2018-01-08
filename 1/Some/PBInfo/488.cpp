#include<iostream>
#include<fstream>
using namespace std;
//ifstream fin("un.in");
int main()
{
	int i,n,v[1001];
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>v[i];
		if(i%2==0)cout<<v[i]<<" ";
	}cout<<"\n";
	if(n%2==0)n--;
	for(i=n;i>=1;i-=2)
	cout<<v[i]<<" ";
}
