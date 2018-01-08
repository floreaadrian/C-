#include<iostream>
using namespace std;
int main()
{
	int a,j,c=0,i,n,k;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		for(j=1;j<=a/2;++j)
		{
			if(a%j==0)c++;
		}
		if(c>=k)cout<<a<<" ";
	}
	return 0;
}
