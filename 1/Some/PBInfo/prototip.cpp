#include<iostream>
using namespace std;
/*ifstream cin("sum.in");
ofstream cout("sum.out");*/
int main()
{
	int a,b,s=0,c,x;
	cin>>a;
	if(a%2!=0)s++;
	if((a/10)%2!=0)s++;
	if((a/100)%2!=0)s++;
	cout<<s;
}
