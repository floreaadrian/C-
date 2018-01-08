#include<iostream>

using namespace std;

float calculDeterminant(float d[][11],int dimensiune)
{
// calculam recursiv un determinant prin dezvoltarea sa pe o line
// daca dimensiunea lui e mai mare decat unu (alegem prima linie)
// daca dimensiunea e unu valoarea sa e acel element unic
  int k,i,j, coef;
  float aux[11][11], delta;
  delta=0; coef=1;
  if (dimensiune==1)
  delta=d[1][1];
  else
  {
    for (k=1;k<=dimensiune;k++)
    {
      for (i=2;i<=dimensiune;i++)
        for (j=1;j<=dimensiune;j++)
        {
        if (j<k)
        aux[i-1][j]=d[i][j];
        if (j>k)
        aux[i-1][j-1]=d[i][j];
        };
        delta=delta+coef*d[1][k]*calculDeterminant(aux,dimensiune-1);
        coef=coef*(-1);
    };
  }
  return delta;
}
bool rezolvareSistem(float A[][11],int dimensiune,float B[], float X[])
{
// daca se poate se calculeaza in X solutia sistemului si
// returneaza true
// daca functia returneaza false
    float aux[11][11];
    float delta;
    int k,i,j;
    delta=calculDeterminant(A,dimensiune);
    if (delta != 0)
    {
      for (k=1;k<=dimensiune;k++)
      {
        for (i=1;i<=dimensiune;i++)
        for (j=1;j<=dimensiune;j++)
          if (k==j)
          aux[i][j]=B[i];
          else
          aux[i][j]=A[i][j];
          X[k]=calculDeterminant(aux, dimensiune)/delta;
      };
      return true;
    }
    else
    return false;
}
void citireMatrice(float a[][11],int nrLinii,int nrColoane)
{
    int i,j;
    for (i= 1; i<= nrLinii;i++)
    for (j= 1;j<=nrColoane;j++)
    cin>>a[i][j];
}

void citireSir(float a[], int dimensiune)
{
    int i;
    for (i=1;i<=dimensiune;i++)
    cin>>a[i];
}

void afisare(float X[],int dimensiune, bool stare)
{
      int i;
      cout<<endl;
      if (stare)
      {
      for (i=1;i<=dimensiune;i++)
      cout<<"x("<<i<<")="<<X[i]<<endl;
      }
      else
      cout<<"Sistem incompatibil sau nedeterminat!";
}
void citireDate(float a[][11],float b[],int & dimensiune)
{
    cout<<"Introduceti numarul necunoscutelor n=";cin>>dimensiune;
    cout<<"Introduceti coeficientii necunoscutelor (matricea ";
    cout<<"sistemului"<<dimensiune<<"x"<<dimensiune<<")"<<endl;
    citireMatrice(a,dimensiune,dimensiune);
    cout<<"Introduceti termenii liberi (matricea termenilor liberi";
    cout<<dimensiune<<"x1)"<<endl;
    citireSir(b,dimensiune);
}
int main()
{
    float A[11][11],X[11],B[11];
    int n;
    citireDate(A,B,n);
    afisare(X,n,rezolvareSistem(A,n,B,X));
    return 0;
}
