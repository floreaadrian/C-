#include<iostream>
using namespace std;
int main()
{
	long i,n,s=1;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		s*=i;
    }
	cout<<s;
}
