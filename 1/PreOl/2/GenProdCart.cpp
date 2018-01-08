#include<fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int n,L[20],E[20];

void citire();
void generare(int);
void afisare();

int main()
{
	citire();
	generare(1);
	return 0;
}

void generare(int k)
{
	int j;
	if(k==n+1)
	afisare();
	else
	for(j=1;j<=L[k];j++)
	{
		E[k]=j;
		generare(k+1);
	}
}

void afisare()
{
	int i;
	for(i=1;i<=n;++i)fout<<E[i]<<" ";
	fout<<"\n";
}

void citire()
{
	fin>>n;
	for(int i=1;i<=n;++i)fin>>L[i];
}
