#include<iostream>
using namespace std;
int main()
{
	int n,i=1,s=0;
	cin>>n;
	while(i*i<=n)
	{
		s+=i*i;
		i++;
	}
	cout<<"Rezultatul este "<<s;
}
