#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,k;
	cin>>n>>k;
	i=pow(10,k);
	if(i>n)cout<<"NUMAR VID";else
	cout<<n%i;
	return 0;
}
