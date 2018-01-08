#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,i,b,n;
	bool ok=true;
	cin>>n;
	a=n/2;
	if(a+a+a+3==n)
	cout<<a<<" "<<a+1<<" "<<a+2;else
	cout<<"NU EXISTA";
}
