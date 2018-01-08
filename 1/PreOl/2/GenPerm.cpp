#include<fstream>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int n,p[40],uz[40];

void afisare()
{
	for(int i=1;i<=n;i++)fout<<p[i]<<" ";
	fout<<"\n";
}

void GenPermutari(int k)
{
	if(k-1==n)
	afisare();
	else
	for(int i=1;i<=n;++i)
	{
		if(!uz[i])
		{
			p[k]=i;uz[i]=1;GenPermutari(k+1);
			uz[i]=0;
		}
	}
}

int main()
{
	fin>>n;
	GenPermutari(1);
	return 0;
}
