#include<iostream>
using namespace std;
int main()
{
	int n,c,no=0;
	cin>>n>>c;
	while(n)
	{
		if(n%10!=c)
		{
			no=no*10+n%10;
		}
		n/=10;
	}
	n=0;
	while(no)
	{
		n=n*10+no%10;
		no/=10;
	}
	if(n==0)
	cout<<-1;
	else cout<<n;
}
