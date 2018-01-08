#include<fstream>
#include<iostream>
using namespace std;

struct Piesa{int prim,ultim;
};
int n,LgMax;
int L[100],LMax[100],Uz[100];
Piesa J[100];

void Citire()
{
	ifstream fin("date.in");
	fin>>n;
	for(int i=1;i<=n;++i)
	{
		fin>>J[i].prim>>J[i].ultim;	
	}
	fin.close();
}
void Afisare()
{
	cout<<"Cel mai lung lant este format din piesele ";
	for(int i=1;i<=LgMax;++i)
	{
		cout<<LMax[i]<<" ";
	}
}

void ConstLant(int k)
//lantul contine k-1 piese de domino
{
	int Se_Poate=0; //incerc sa prelungesc lantul
	for(int i=1;i<=n;++i)
		if(!Uz[i]) //nu am utilizat piesa i
		{
			if(J[i].ultim==J[L[k-1]].ultim)//ultima piesa
			{
				int aux=J[i].prim;
				J[i].prim=J[i].ultim;
				J[i].ultim=aux;
			}
			if(J[i].prim==J[L[k-1]].ultim) //piesa i se lipeste
			{
				L[k]=i;Uz[i]=1;Se_Poate=1;
				ConstLant(k+1);Uz[i]=0;
			}
		}
		if(!Se_Poate) //am obtinut o solutie maximala
		if(k-1>LgMax) //compar lantul curent cu cel maxim
	{
		LgMax=k-1;
		for(int i=1;i<=LgMax;++i) LMax[i]=L[i];
	}
}

int main()
{
	Citire();
	for(int i=1;i<=n;++i)
	{
		//pot incepe lantul cu orice piesa
		L[1]=i;Uz[i]=1;
		ConstLant(2);
		Uz[i]=0;
	}
	Afisare();
	return 0;
}
