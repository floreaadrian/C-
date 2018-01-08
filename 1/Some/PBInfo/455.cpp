#include<iostream>
using namespace std;
int main()
{
	int z1,l1,a1;
	cin>>z1>>l1>>a1;
	if(l1==12)
	{
		if(z1==31)
		cout<<01<<" "<<01<<" "<<a1+1;
	}else
	if(z1==31 && (l1%2!=0 || l1==1 || l1==8))
	{
		cout<<01<<" "<<l1+1<<" "<<a1;
	}else
	if(z1==30)
	cout<<01<<" "<<l1+1<<" "<<a1;else
	cout<<z1+1<<" "<<l1<<" "<<a1;
}
