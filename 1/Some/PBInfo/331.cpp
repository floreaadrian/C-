#include<iostream>
using namespace std;
int main()
{
	int n,i;
	cin>>n;
	for(i=n*2;i>=1;i--)
	if(i%2!=0)cout<<i<<" ";
	return 0;
}
