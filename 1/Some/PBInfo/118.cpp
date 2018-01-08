#include<iostream>
using namespace std;
int main()
{
	int n,s=0,no,ma=0;
	cin>>n;no=n;
	do
	{
		if(n%10>ma){
			ma=n%10;
		}
		n/=10;
	}while(n);
	do
	{
		if(no%10==ma)s++;
		no/=10;
	}while(no);
	cout<<ma<<" "<<s;
}
