#include<iostream>
using namespace std;
int main()
{
	long a=0,b=0,s=1,i,n;
	cin>>n;
	do
	{
		if(n%10==2)a++;else
		b++;n/=10;
	}while(n>0);
	if(b>a)
	cout<<3;else
	if(a>b)
	cout<<2;else if(a==b)cout<<2<<" "<<3;
}
