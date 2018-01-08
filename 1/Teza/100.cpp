#include <iostream>
using namespace std;
int main()
{
    int i;
    for(i=1000;i<=9999;++i)
    if(i%10>i%100/10 && i%100/10<i%1000/100 && i%1000/100>i/1000)
        cout<<i<<" ";
    return 0;
}
