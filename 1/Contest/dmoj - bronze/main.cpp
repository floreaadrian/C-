#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

bool is_perfect_square(int n) {
    if (n < 0)
        return false;
    int root(round(sqrt(n)));
    return n == root * root;
}

int main()
{
    int a,b,nr=0;
    cin>>a>>b;
    if(a>b)swap(a,b);
    for(int i=a;i<=b;i++)
    {
        if(is_perfect_square(i))
            nr++;
    }
    cout<<nr;
    return 0;
}
