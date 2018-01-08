#include<iostream>
using namespace std;
int main()
{
	int n,ulp=0,ulp1=0,i,a;
	cin>>n;
	for(i=1;i<=n;++i)
	{
		cin>>a;
		if(a%2!=0)
		{
			ulp1=ulp;
			ulp=a;
		}
	}
	if(ulp1!=0)
	cout<<ulp1<<" "<<ulp;
	else cout<<"Numere insuficiente";
}
