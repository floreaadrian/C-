#include<iostream>
#include<math.h>

using namespace std;

float c;

int cauta(int a,int b)
{
	int c=b;
	bool ok=true;
	while(a<=c)
	{
		b=c;
		if(b%2==0)
		{
			while(b)
			{
				b/=2;
			}
			if(b==2)
			{
				cout<<c<<"\n";break;
			}
		}c--;
	}
	cout<<"0\n";
}

int main()
{
	int n,a,b;
	
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a>>b;
		c=0;
		if(a>b)
		{
			int aux=a;
			a=b;
			b=a;
		}
		cauta(a,b);
	}
	return 0;
}
