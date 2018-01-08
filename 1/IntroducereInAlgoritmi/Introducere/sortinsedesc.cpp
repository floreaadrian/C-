#include<fstream>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

int main()
{
	int a[1000],n,i,j;
	fin>>n;
	for(i=1;i<=n;i++)
	fin>>a[i];
	for(j=2;j<=n;j++)
	{
		int cheie=a[j];
		i=j-1;
		while(i>0 && a[i]<cheie)
		{
			a[i+1]=a[i];
			i--;
			a[i+1]=cheie;
		}
	}
	for(i=1;i<=n;i++)
	fout<<a[i]<<" ";
	return 0;
}
