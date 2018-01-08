#include<iostream>
using namespace std;
int main()
{
	int n,d,p,y=0,x=0,i,k,z;
	cin>>z;
	for(i=1;i<=z;++i)
	{
		cin>>n>>k;
		if(n==1)
		{
			x+=k;
		}
		else
		if(n==2)
		{
			x+=k;
			y+=k;
		}
		else
		if(n==3)
		{
			y+=k;
		}
		else
		if(n==4)
		{
			x+=k;
			y-=k;
		}
		else
		if(n==5)
		{
			y-=k;
		}
		else
		if(n==6)
		{
			y-=k;;
			x-=k;
		}
		else
		if(n==7)
		{
			x-=k;
		}
		else
		if(n==8)
		{
			x-=k;
			y+=k;
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
