#include<fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int m,n,s[100],NrUnu=0;

void afisare();
void bin(int);

void bin(int k)
{
	if(k==m)
	afisare();
	else
	{
		if(k-NrUnu<m-n)
		{
			s[k]=0;
			bin(k+1);
		}
		if(NrUnu<n)
		{
			s[k]=1;NrUnu++;
			bin(k+1);
			NrUnu--;
		}
	}
}
void afisare()
{
	for(int i=1;i<=m;++i)
	fout<<s[i];
	fout<<"\n";
}
int main()
{
	fin>>m>>n;
	bin(1);
	return 0;
}
