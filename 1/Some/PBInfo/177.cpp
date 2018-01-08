#include<iostream>
using namespace std;
int main()
{
	int a,a1,a2,a3;
	cin>>a;
	a1=a%10;
	a2=(a/10)%10;
	a3=a/100;
	if((a1>a2 && a1<a3) || (a1>a3 && a2<a1))cout<<a1;
	if((a2>a1 && a2<a3) || (a2>a3 && a2<a1))cout<<a2;
	if((a3>a2 && a3<a1) || (a3>a1 && a3<a2))cout<<a3;
}
