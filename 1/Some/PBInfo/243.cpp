#include<iostream>

using namespace std;

int main()
{
	int n,c,p,i;
	cin>>n;
	c=i=1;
	while(i<n)
	{
		p=c;
		while(p!=0 && i<n)
		{
			p--;
			i++;
		}
		c++;
	}
	cout<<p;
	return 0;
}
