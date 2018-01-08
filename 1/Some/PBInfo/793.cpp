#include<iostream>
using namespace std;
int main()
{
	int a,a1,a2,a3,s1,s2,s3;
	cin>>a1>>a2>>a3;
	s1=(a1*a2)+a3;
	s2=(a1*a3)+a2;
	s3=(a2*a3)+a1;
	if(s1>s2 && s1>s3)cout<<s1;
	else if(s2>s1 && s2>s3)cout<<s2;
	else if(s3>s2 && s3>s1)cout<<s3;
}
