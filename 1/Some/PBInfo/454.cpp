#include <iostream>
using namespace std;
int main()
{
   int z,l,a;
   cin>>z>>l>>a;
   if((z>0&&z<=31) && (l<=12&&l>0) && a!=0)
   cout<<"DA";
   else
   cout<<"NU";
   return 0;
}
