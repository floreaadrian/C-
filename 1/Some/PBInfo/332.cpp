#include<iostream>
#include<limits.h>
using namespace std;
int main()
{
	long i,n,s=0,max;
	cin>>n;
	if(n==0){
	cout<<"NU EXISTA";
	return 0;
	}
	max=n;
	while(n!=0)
	{
		if(n>max)max=n;
		cin>>n;
	}
	cout<<max;
}
