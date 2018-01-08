#include<iostream>
#include<cmath>
#include<limits.h>
using namespace std;
int main()
{
	int n,a,ma1,ma2,dif=INT_MAX,a1;
	cin>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		if(((abs)(a-a1))<dif)
		{
			ma1=a;ma2=a1;
		}
		a1=a;
	}
	cout<<ma1<<" "<<ma2;
}
