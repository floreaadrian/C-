#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	int ma=INT_MIN,n,i,c=0,a;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a>ma && a<0)
		{
			c=1;ma=a;
		}else
		if(a==ma)c++;
	}
	if(c==0)
	{
		cout<<"NU EXISTA";
	}else
	cout<<ma<<" "<<c;
}
