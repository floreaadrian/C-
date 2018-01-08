#include<fstream>
using namespace std;
ifstream fin("div3.in");
ofstream fout("div3.out");
int suma_cifre(int n)
{
	int s=0;
	while(n)
	{
		s+=n%10;
		n/=10;
	}
	return s;
}
int main()
{
	int n,i,a;
	fin>>n;
	for(i=1;i<=n;++i)
	{
		fin>>a;
		if(suma_cifre(a)%3==0)
		fout<<a<<" ";
	}
}
