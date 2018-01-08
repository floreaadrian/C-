#include<fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int n,v[1000];

void tr(int);
void af();

void tr(int n)
{
	while(n)
	{
		v[n%10]++;
		n/=10;
	}
}

void af()
{
	for(int i=9;i>=0;i--)
	{
		while(v[i])
		{
			fout<<i;
			v[i]--;
		}
	}
	fout<<"\n";
}

int main()
{
	int a,b;
	fin>>a>>b;
	tr(a);tr(b);
	af();
	return 0;
}
