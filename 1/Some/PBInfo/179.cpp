#include<iostream>
using namespace std;
int main()
{
	float a,b,c;
	cin>>a>>b>>c;
	 if((a<b+c)&&(b<a+c)&&(c<a+b) && (a>0 && b>0 && c>0))
	cout<<"da";else
	cout<<"nu";
}
