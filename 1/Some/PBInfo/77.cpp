#include<iostream>
using namespace std;
int main()
{
	long long n,i,x=0;
	cin>>n;
	while(n)
	{
		if(n%2==0 && n%10!=0){
			cout<<n%10;
			return 0;
		}
		n/=10;
	}
	cout<<-1;
}
