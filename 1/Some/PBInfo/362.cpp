#include<iostream>
using namespace std;
int main()
{
	int c=1,n,s=0;
	cin>>n;
	while(n)
	{
		if(c%2!=0)
		{
			s+=n%10;
		}
		n/=10;
		c++;
	}
	cout<<s;
}
