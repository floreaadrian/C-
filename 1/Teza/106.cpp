#include<iostream>
using namespace std;
int main()
{
	int n,i=10,j;
	while(i<100)
	{
		for(j=1;j<=5;++j)
		{
			cout<<i<<" ";i+=2;
		}cout<<"\n";
	}
	return 0;
}
