#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int n,k,a,b;
	cin>>n>>k;
	if(n%k==0)cout<<n;
	else 
	{
		a=b=n;
		while(a%k!=0)
		{
			a++;
		}
		while(b%k!=0)
		{
			b--;
		}
		if(a-n<n-b)
		cout<<a;else 
		cout<<b;
	}
}
