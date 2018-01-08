#include <iostream>

using namespace std;

void citireDate(int & inputN,int & inputM)
{
 cout<<" Introduceti dimensiunea matricii n=";cin>>inputN;
 cout<<" Introduceti numarul m="; cin>>inputM;
}

void matriceInitiala1(int matrice[][21],int n,int m)
{
// genereaza prima matrice din secventa conform primei reguli
// se parcurge efectiv matricea pe directii paralele cu diagonala
// secundara
    int i,j;
    for(i=1;i<=n;i++)
    matrice[i][n-i+1]=m;
    for (i=1;i<=n;i++)
    for (j=n-i;j>=1;j--)
    matrice[i][j]=matrice[i][j+1]-1;
    for (i=2;i<=n;i++)
    for (j=n-i+2;j<=n;j++)
    matrice[i][j]=matrice[i][j-1]+1;
}

void matriceInitiala2(int matrice[][21], int n, int m)
{
// genereaza prima matrice din secventa conform primei reguli
// observand modul cum ar arata valorile in ea
    int i,j;
    for (j=n;j>=1;j--)
    matrice[1][j]=m-n+j;
    for (i=2;i<=n;i++)
    for (j=1;j<=n;j++)
    matrice[i][j]=matrice[i-1][j]+1;
}

int nrDivizoriProprii(int nr)
{
    // numaram divizorii proprii ai argumentului functiei
    int i, numar;
    numar=0;
    if (nr>2)
    {
    for (i=2;i<=(nr / 2)+1;i++)
    if ((nr % i)==0)
    numar++;
    }
    return numar;
}

void matriceSecundara(int matrice[][21],int n)
{
// generarea matricilor dupa a doua regula
    int i,j;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    matrice[i][j]=nrDivizoriProprii(matrice[i][j]);
}

bool testMatrice(int matrice[][21],int n)
{
// testam daca matricea este matricea nula
    bool indicator=true;
    int i,j;
    for (i=1;i<=n;i++)
    for (j=1;j<=n;j++)
    if (matrice[i][j]!=0)
    indicator=false;
    return indicator;
}

void afisareMatrice(int matrice[][21],int n)
{
    int i,j;
    for (i=1;i<=n;i++)
    {
    cout<<endl;
    for (j=1;j<=n;j++)
    cout<<' '<< matrice[i][j];
    }
    cout<<endl;
}

int main()
{
    int n,m;
    citireDate(n,m);
    int a[21][21];
    matriceInitiala1(a,n,m); //matriceInitiala2(a,n,m);
    afisareMatrice(a,n);
    while (! testMatrice(a,n))
    {
      matriceSecundara(a,n);
      afisareMatrice(a,n);
    }
    return 0;
}
