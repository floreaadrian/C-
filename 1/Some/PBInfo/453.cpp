#include<iostream>
using namespace std;
int main()
{
	int a,b,c,con=0;
	cin>>a>>b>>c;
	if(a!=b && a!=c && c!=b)con=3;
	if(a==b && a==c)con=1;
	if((a==c && a!=b) || (a==b && a!=c) || (b==c && c!=a))con=2;
	cout<<con;
}
