#include<fstream>

using namespace std;

int ma(int a,int b)
{
	if(a>b)return a;
	return b;
}

ifstream fin("date.in");
ofstream fout("date.out");

int inst[10000],d[10000],min1[10000],n;

int main()
{
	fin>>n;
	for(int i=0;i<n;i++)
	fin>>inst[i]>>d[i];
	min1[n-1]=d[n-1];
	for(int i=n-2;i>=0;i--)
	{
		min1[i]=d[i]+ma(0,min1[i+1]-inst[i]);
	}
	fout<<min1[0];
	return 0;
}
