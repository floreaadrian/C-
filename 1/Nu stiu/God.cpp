#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,i,j,b;
	cin>>a;
	cin>>b;
	for(i=1;i<=a;++i)
	{
		if(pow(b,i)==a)
		{
			cout<<i;
			break;
		}
	}
	return 0;
}
