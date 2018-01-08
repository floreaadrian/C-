#include<iostream>
using namespace std;
int main()
{
	int n,no,c=0;
	cin>>n;
	while(no!=0)
	{
		cin>>no;
		if(no==0 && n%10==0)
		{
			break;
		}
		if(n%10==no%10)c++;
		n=no;
	}
	cout<<c;
}
