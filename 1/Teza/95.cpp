#include<iostream>
using namespace std;
int main()
{
	int a,b,n,i=2;
	cin>>a;
	while(a>1)
	{
		if(a%i!=0){
			cout<<"NU";
			return 0;
		}a/=i;
		i++;
	}
	cout<<"DA";
}
