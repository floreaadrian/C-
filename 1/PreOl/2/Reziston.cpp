#include<fstream>
#include<string.h>
using namespace std;
ifstream fin("date.in");
ofstream fout("date.out");
int n,p=0,LMax=1001;

char s[1001];
long r;

void citire();
void afisare();
long rezserie();
long rezparalel();

int main()
{
	citire();
	r=rezserie();
	afisare();
	return 0;
}

void citire()
{
	fin>>s;
	n=strlen(s);
	fin.close();
}
void afisare()
{
	fout<<r<<" ";
	fout.close();
}

long rezserie()
{
	long val,suma=0;
	if(p>n || s[p]==',' || s[p]==')')
	return 0;
	while(p<n && s[p]!=',' && s[p]!=')')
		if(s[p]=='R')
		{
			p++;
			val=s[p]-'0';
			p++;
			if(s[p]>='0' && s[p]<='9')
			{
				val=val*10+s[p]-'0';
				p++;
			}
			suma+=val;
		}
		else suma+=rezparalel();
		return suma;
}
long rezparalel()
{
	long suma=0,produs=1,val;
	while(s[p]!=')')
	{
		p++;
		val=rezserie();
		suma+=val;
		produs*=val;
	}p++;
	return produs/suma;
}
