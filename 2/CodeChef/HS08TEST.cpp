#include<iostream>
#include<iomanip>
using namespace std;
int main()
{
	int x,y;
	float s;
	cin>>x>>y;
	if(x%5!=0)cout<<fixed<<setprecision(2)<<y;
	else
	if(x>y)cout<<fixed<<setprecision(2)<<y;
	else {
		s=(float)y-x-((x/5)*0.5);
		cout<<fixed<<setprecision(2)<<s;
	}
	
}
