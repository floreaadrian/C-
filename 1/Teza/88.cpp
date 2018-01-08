#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{
	int n,i;
	float m=1;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		m-=sqrt(i);i++;
		m+=sqrt(i);
	}
	cout<<fixed<<setprecision(4)<<m;
}
