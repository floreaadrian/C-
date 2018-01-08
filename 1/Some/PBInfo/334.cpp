#include<iostream>
#include<cmath>
using namespace std;
int main()
{
	int n,i,s=1;
	cin>>n;
	for(i=2;i<=n;++i)
	{
		s+=pow(i,i);
	}
	cout<<"Rezultatul este "<<s;
}
