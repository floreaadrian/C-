#include<iostream>
#include<math.h>
using namespace std;

int n;

int re(int a)
{
	if(a+2==n)return n;
	else re(pow(a,2));
}

int main()
{
	cin>>n;
	cout<<re(n);
}
