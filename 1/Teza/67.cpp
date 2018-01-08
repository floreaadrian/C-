#include<iostream>
using namespace std;
int main()
{
	int ma=30000,c=0,i,n,a;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a<ma && a>0)
		{
			c=1;ma=a;
		}else
		if(a==ma){
			c++;
		}
	}
	cout<<ma<<" "<<c;
}
