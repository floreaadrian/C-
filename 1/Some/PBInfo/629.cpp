#include<iostream>
#include<math.h>
using namespace std;
int x1,x2;
void afla(int k)
{
	int del;
	del=1+k*4;
	x1=(-1+sqrt(del))/2;
	x2=(-1-sqrt(del)/2);
}
int main()
{
	int k,n,z,p;
	cin>>p;
	cin>>k>>n;
	afla(k);
	cout<<pow(x2,2)+(1/pow(x2,2));
}

