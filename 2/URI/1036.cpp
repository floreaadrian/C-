#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;
int main()
{
	float a,b,c;
	double a1,a2,d;
	cin>>a>>b>>c;
	d=b*b-(4*a*c);
	if(d<0 || a==0 || b==a)
	cout<<"Impossivel calcular";
	else
	{
		a1=(double)(-b-sqrt(d))/(2*a);
		a2=(double)(-b+sqrt(d))/(2*a);
		cout<<"R1 = "<<fixed<<setprecision(5)<<a2<<"\n";
		cout<<"R2 = "<<fixed<<setprecision(5)<<a1;
	}
}
