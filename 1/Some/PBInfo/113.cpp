#include<iostream>
using namespace std;
int nr_cif(int x,int y)
{
	int s=0;
	while(x>0)
	{
		if(x%10!=0)
		{
		if(y%(x%10)==0)s++;
		}
		x/=10;
	}
	return s;
}
int main()
{
	int x,y;
	cin>>x>>y;
	cout<<nr_cif(x,y);
}
