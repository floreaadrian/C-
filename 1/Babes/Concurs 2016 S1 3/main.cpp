//Subiectul 1 exercitiul 3
#include <iostream>

using namespace std;

struct pun{
    int a,b,c;
} re;

int main()
{
    int x[10005],n;
    cin>>n;
    for(int i=1;i<=n;++i)
        cin>>x[i];
    int ma=0;
    for(int i=1;i<=n;++i)
        for(int j=i+1;j<=n;++j)
            for(int k=j+1;k<=n;++k)
                if(x[i]*x[j]*x[k]>ma && i!=j && k!=j)
                {
                    ma=x[i]*x[j]*x[k];
                    re.a=x[i];
                    re.b=x[j];
                    re.c=x[k];
                }
    cout<<re.a<<" "<<re.b<<" "<<re.c;
    return 0;
}
