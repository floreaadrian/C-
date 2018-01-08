#include<iostream>
#include<math.h>
using namespace std;
int main()
{
	float m,a,b,c;
	cin>>a>>b>>c;
	m=sqrt((a*b));
	if(c==m)
	{
		cout<<"DA";return 0;
	}
    m=sqrt((c*b));
	if(a==m)
	{
		cout<<"DA";return 0;
	}
	m=sqrt((a*c));
	if(b==m)
	{
		cout<<"DA";return 0;
	}
	cout<<"NU";
	return 0;
}
