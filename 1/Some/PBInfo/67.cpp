#include<iostream>
using namespace std;

int a_prim(int x)
{
       int d,nr;
       d=2;
       nr=0;
       while(x>1 && nr<=2)
       {  while(x%d==0 && nr<=2) { nr++;
                                   x=x/d;
                                 }
          d++;               
       }
       if(nr==2)
	   return 1;
	   return 0;   
}
int main()
{
	int x;
	cin>>x;
	cout<<a_prim(x);
}
