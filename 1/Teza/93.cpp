#include <iostream>
#include <math.h>
using namespace std;
int main()
{
    int xa,xb,ya,yb,da,db;
    cin>>xa>>ya>>xb>>yb;
    da=sqrt(pow(xa,2)+pow(ya,2));
    db=sqrt(pow(yb,2)+pow(yb,2));
    if(da==db)
        cout<<"DA";
    else
        cout<<"NU";
    return 0;
}
