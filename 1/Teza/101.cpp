#include<iostream>
using namespace std;
int fr[10];
int main()
{
	int b,n=0,a,i;
	cin>>a>>b;
	while(a)
	{
		fr[a%10]++;
		a/=10;
	}
	while(b)
	{
		fr[b%10]++;
		b/=10;
	}
	for(i=9;i>=0;i--)
	{
		while(fr[i])
		{
			cout<<i;fr[i]--;
		}	
	}
}
