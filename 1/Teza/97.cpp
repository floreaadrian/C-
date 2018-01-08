#include<iostream>
using namespace std;
int main()
{
	int n,a,b,i;
	cin>>n;
	a=n%10;
	b=(n/10)%10;
	n/=10;
	while(n)
	{
		if(n%10!=b || (n/10)%10!=a)
		{
			cout<<"NU";return 0;
		}
		n/=100;
	}
	cout<<"DA";
}
