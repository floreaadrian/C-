#include<iostream>
using namespace std;
int main()
{
	int a=0,b=0,s=1,i,n;
	cin>>n;
	while(n>0)
	{
		if(n%10==2)a++;else
		b++;n/=10;
	}
	if(b>a)
	cout<<3;else
	if(a>b)
	cout<<2;else if(a==b)cout<<2<<" "<<3;
}
