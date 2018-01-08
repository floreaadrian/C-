#include<iostream>
using namespace std;
int main()
{
	int n,c;
	cin>>n;
	c=n%10;
	n/=10;
	while(n)
	{
		if(n%10!=c)
		{
			cout<<"NU";return 0;
		}
		n/=10;
	}
	cout<<"DA";
	return 0;
}
