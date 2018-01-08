#include<iostream>
using namespace std;
int main()
{
	int n,i,x=0,c=9;
	cin>>n;
	while(n)
	{
		if(n%10>x)x=n%10;
		if(n%10<c)c=n%10;
		n/=10;
	}
	cout<<x+c;
}
