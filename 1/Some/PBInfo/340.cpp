#include<iostream>
using namespace std;
int main()
{
	int n,s=0;
	bool ok=true;
	cin>>n;
	while(n>9)
	{
	while(n>0)
	{
		s+=n%10;
		n/=10;
	}
	n=s;s=0;
    }
    cout<<n;
}
