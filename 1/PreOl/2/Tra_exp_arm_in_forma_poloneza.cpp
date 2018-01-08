#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

char e[200],p[200];
int lg,i,lgp;

void TransformExpresie();
void TransformTermen();
void TransformFactor();

int main()
{
	cout<<"Introduceti expresia ";cin.getline(e,200);
	lg=strlen(e);
	TransformExpresie();
	cout<<"Expresia in forma poloneza "<<p<<"\n";
	  return 0;
}
void TransformFactor()
{

	if(e[i]=='(') //factorul e o expresie intre paranteze
	{
		i++; //trec peste (
		TransformExpresie(); //transofrm expresia din paranteza
		i++; //trec peste (
	}else //factorul este o litera sau cifra
	p[lgp++]=e[i++];
}
void TransformTermen()
{
	TransformFactor(); //transfosrm primul factor al termenului
	while(i<lg && e[i]=='*') //mai urmeasa factori
	{
		i++; //trec peste *
		TransformFactor();
		p[lgp++]='*';
	}
}
void TransformExpresie()
{
	TransformTermen(); //transform primul factor al termenului
	while(i<lg && e[i]=='+') //mai urmeaza termeni
	{
		i++; //trec peste +
		TransformFactor();
		p[lgp++]='+';
	}
}
