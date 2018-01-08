#include<fstream>
using namespace std;
ifstream fin("numere8.in");
ofstream fout("numere8.out");
int main()
{
	int v[100001],i,n;
	while(fin>>n)
	{
		v[n]++;
	}
	for(i=9999;i>=1;i--)
	if(!v[i])fout<<i<<" ";
}
