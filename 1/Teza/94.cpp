#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float b,x;
	int a,i=1,b1;
	bool ok=true;
	cin>>x;
	while(ok)
	{
		b=i*x;
		b1=b;
		if(b1==b)
		{
			cout<<i<<" "<<b;
			return 0;
		}
		i++;
	}
}
