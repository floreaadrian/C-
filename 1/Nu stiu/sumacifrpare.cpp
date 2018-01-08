#include<iostream>
using namespace std;
int main()
{
	int x,suma=0; //x este numarul pe care o sa il citim si suma este suma cifrelor pare pe care o sa o calculam
	
	cin>>x; //il citim pe x
	
	while(x>0) //programul verifica daca x este mai mare decat 0 , daca este mai maredecat 0 executa instructiunile care le dam
	{
		if(x%2==0) //verificam daca numarul este par , verificam daca tot numarul este par pentru ca daca este par si ultima cifra va fi para
		
		suma=suma+x%10; //am adunat la suma x%10 , x%10 fiind ultima cifra a numarului 
		
		x=x/10; //si daca ultima cifra este para si daca nu e noi trebuie sa continuam la urmatoarea cifra , facem asta stergand ultima cifra actuala 
	
	} //noi acum am terminat de executat tot din instructuiunea while , acum o sa mergem iar si o sa verificam conditiile de mai sus
	
	cout<<suma; //afisam suma chiar daca nu avem nicio cifra para pentru ca o sa fie suma egala cu 0

	return 0;
}

