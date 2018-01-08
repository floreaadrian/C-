#include<iostream>
using namespace std;
int main()
{
	int n,i,s=0;
	cin>>n;
	while(n)
	{
		s+=n*n;
		n--;
	}
	cout<<"Rezultatul este "<<s;
}
