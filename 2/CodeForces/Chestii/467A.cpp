#include<iostream>
using namespace std;
int main()
{
	int n,i,a,b,c=0;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a>>b;
		if(a<=b-2)c++;
	}
	cout<<c;
}
