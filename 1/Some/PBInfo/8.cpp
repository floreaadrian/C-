#include<fstream>
#include<iostream>
using namespace std;
ifstream fin("maxim3.in");
ofstream fout("maxim3.out");
int main()
{
	int ma,a,b,c;
	fin>>a>>b>>c;
	if(a>b && a>c)fout<<a;
	else if(b>a && b>c)fout<<b;
	else if(c>a && c>b)fout<<c;
}
