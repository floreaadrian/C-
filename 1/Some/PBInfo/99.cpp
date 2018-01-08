#include<fstream>

using namespace std;

ifstream fin("nraparitii.in");
ofstream fout("nraparitii.out");

int main()
{
	int v[101],i,n,c=1;
	fin>>n;
	for(i=1;i<=n;i++)
	fin>>v[i];
	for(i=1;i<n;i++)
	if(v[n]==v[i])
	c++;
	fout<<c;
	return 0;
}
