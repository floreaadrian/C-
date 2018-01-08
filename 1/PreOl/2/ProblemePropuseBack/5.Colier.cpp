#include<fstream>
#include<string.h>

using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

char c[100];
int n,Nr=0;

void Gen(int);
void afisare();

void Gen(int k)
{
	if(k-1==n)
	if(c[1]!=c[n] && !(c[1]=='a'&&c[n]=='g'|| c[1]=='g' && c[n]=='a') && !(c[1]=='n'&&c[n]=='v' || c[1]=='v' && c[n]=='n'))
	afisare();
	else;
	else
	{
		if(Nr<n/2 && c[k-1]!='r')
		{
			c[k]='r';Nr++;
			Gen(k+1);
			Nr--;
		}
		if(c[k-1]!='a' && c[k-1]!='g')
		{
			c[k]='a';Gen(k+1);
			c[k]='g';Gen(k+1);
		}
		if(c[k+1]!='n' && c[k-1]!='v')
		{
			c[k]='n';Gen(k+1);
			c[k]='v';Gen(k+1);
		}
	}
}

void afisare()
{
	for(int i=1;i<=n;++i)
	fout<<c[i]<<" ";
	fout<<"\n";
}

int main()
{
	c[0]='j';
	fin>>n;
	Gen(1);
	return 0;
}
