#include<iostream>
#include<math.h>
using namespace std;
int nr_prim(int n)
{
	bool prim=true;
	while(prim)
	{
	  int d1=sqrt(n);
	  for(int i=2;i<=d1;++i)
	  {
	  	if(n%i==0) prim=true;
	  	else prim=false;
	  }
	  if(!prim)
	  return n;
	  n--;
	}
}
int main()
{
	int n;
	cin>>n;
	cout<<nr_prim(n);
}
