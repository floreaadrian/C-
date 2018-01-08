#include<iostream>
using namespace std;
int main()
{
	int n,m;
	cin>>n>>m;
	if(n>m){
	cout<<"Restul: "<<n%m;
    cout<<" Catul: "<<n/m;
	}else
	{
	cout<<"Restul: "<<m%n;
    cout<<" Catul: "<<m/n;
	}
}
