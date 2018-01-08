#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	int a,b,s=1,k=1;
	cin>>a>>b;
	do
	{
		
		cout<<s<<" ";
		s=pow(a,k);
		k++;
	}while(s<=b);
}
