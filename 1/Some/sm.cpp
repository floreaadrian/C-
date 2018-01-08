#include<iostream>
#include <cstdlib>
#include<string.h>
using namespace std;
int main()
{
	int s;
	char a[10],b[10];
	cin>>a;
	strcpy(b,a[0],2);
	strcpy(b,a[3],2);
	s=atoi(b);
	cout<<s;
}
