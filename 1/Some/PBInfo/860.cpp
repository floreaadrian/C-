#include<iostream>
using namespace std;
int main()
{
	int a,n,i,k,c=0,s=0;
	cin>>n>>k;
	for(i=1;i<=n;i++)
	{
		cin>>a;s+=a;
		while(s<=k)
		{
			cin>>a;i++;s+=a;
		}cout<<s<<"\n";
		s=0;
		c++;
	}
	cout<<c;
}
