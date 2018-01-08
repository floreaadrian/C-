#include<iostream>
#include<string.h>
#include<ctype.h>
using namespace std;

char e[200],op[]="0123456789abcdefghijklmnopqrstuvxyz ";
int lg,i,ND;

int ValidareExpresie();
int ValidareTermen();
int ValidareFactor();

int main()
{
	cout<<"Introduceti expresia ";cin.getline(e,200);
	lg=strlen(e);
	if(ValidareExpresie())
	  cout<<"Expresia este sintactic corecta!\n";
	  return 0;
}
int ValidareFactor()
{
	int r=1;
	if(e[i]=='(') //factorul e o expresie intre paranteze
	{
		ND++; //numar o paranteza deschisa care nu e inchisa
		i++; //trec peste (
		r=ValidareExpresie(); //valudez expresia dintre paranteze
		if(!r) return r; //expresie incorecta
		if(e[i]!=')') //paranteza inchisa corect?
		{
			cout<<"Eroare! Pe pozitia "<<i<<" este necesara )";
			r=0;
		}
		else
		{
			i++; //trc peste (
			ND--; //scar numarul de paranteze ramase deschise
		}
	}else //verific daca factorul este o litera sau o cifra 
	if(!strchr(op,tolower(e[i])))
	{
		cout<<"Eroare!Pe pozitia "<<i<<" trebuie un operand";
		r=0;
	}
	else while(strchr(op,tolower(e[i])))
	{
		i++;
	} //trec peste factor
	return r;
}
int ValidareTermen()
{
	int r=ValidareFactor(); //validare primul factor din termen
	while(r && i<lg && e[i]=='*') //mai urmeasa factori
	{
		i++; //trec peste *
		r=ValidareFactor();
	}
	return r;
}
int ValidareExpresie()
{
	int r=ValidareTermen(); //validez primul termen
	while(r && i<lg && e[i]=='+') //mai urmeaza termeni
	{
		i++; //trec peste +
		r=ValidareTermen();
	}
	if(r && i<lg)
	if(e[i]!=')' || e[i]==')' && !ND)
	{
		cout<<"Eroare!";r=0;
	}
	return r;
}
