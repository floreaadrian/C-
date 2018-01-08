#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    cin>>n;
    while(n--){
        char are[15];
        cin>>are;
        cout<<are[0]<<" "<<are[10];
    }
    return 0;
}
