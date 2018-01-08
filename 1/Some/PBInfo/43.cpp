#include<iostream>
using namespace std;
double nreal(double x,double y)
{
	if(y<10)
	{
		x*=10;
		x=(double)(x+y)/10;
	}else
	if(y<100 && y>=10)
	{
		x*=100;
		x=(double)(x+y)/100;
	}else
	if(y<1000 && y>=100)
	{
		x*=1000;
		x=(double)(x+y)/1000;
	}else
	if(y==1000)
	{
		x=x*10;
		x=(double)(x+1)/10;
	}
	return x;
}
int main()
{
	int x,y;
	cin>>x>>y;
	cout<<(double)nreal(x,y);
}
