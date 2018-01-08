#include<iostream>
using namespace std;

int sumacif(int n)
{
if(n==0) return 0;
else return n%10 + sumacif(n/10);
}

int main()
{
	int n,s=0;
	cin>>n;
	cout<<sumacif(n);
}
