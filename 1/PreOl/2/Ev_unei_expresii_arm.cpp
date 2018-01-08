#include<fstream>
#include<iostream>
#include<string.h>
using namespace std;

struct ab{char ns;int v;
};
ab TS[200];
char e[200];
int i,lg;
void Citire();
int eval(char);
int EvaluareExpresie();
int EvaluareFactor();
int EvaluareTermen();
int main()
{
	Citire();
	cout<<"Valoare expresiei este: "<<EvaluareExpresie();
	return 0;
}
void Citire()
{
	ifstream fin("date.in");
	int NrS=0;
	fin.getline(e,200);lg=strlen(e);
	while(!fin.eof())
	{
		fin>>TS[NrS].ns>>TS[NrS].v;
		NrS++;
	}
	fin.close();
}
int eval(char c)//funtia intoarce valoare operandului c 
{
	if(c>='0' && c<='9')return c-'0'; //cauta valoarea variabilei in tabela de simboluri
	for(int k=0;TS[k].ns!=c;k++)
	return TS[k].v;
}
int EvaluareFactor()
{
	int f;
	if(e[i]=='(') //factorul e o expresie intre paranteze
	{
		i++;
		f=EvaluareExpresie();
		i++; //trece peste '(';
	}else //factorul este o litera sau o cifra
	{
		f=eval(e[i]); 
		i++; //trec peste factor
	}
	return f;
}
int EvaluareTermen()
{
	int f=EvaluareFactor(); //evaluez primul factor
	while(i<lg && e[i]=='*') //mai urmeaza factori 
	{
		i++; //trc peste *
		f*=EvaluareFactor();
	}
	return f;
}
int EvaluareExpresie()
{
	int t=EvaluareTermen(); //evaluez primul termen
	while(i<lg && e[i]=='+') //mai urmeaza termeni
	{
		i++; //trec peste +;
		t+=EvaluareTermen();
	}
	return t;
}
