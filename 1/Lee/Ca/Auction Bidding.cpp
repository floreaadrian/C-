#include<fstream>
#include<string.h>
using namespace std;
ifstream fin("input-level1.txt");
ofstream fout("output-level1.txt");
int main()
{
	int n,m=0,ma=0;
	string a,no;
	fin>>n>>a;
	no=a;ma=n;m=1;
	while(getline.fin>>n && getline.fin>>a)
	{
		if(n>ma)
		{
			ma=n;
			no=a;
		}
	}
	fout<<no<<","<<ma;
	return 0;
}
