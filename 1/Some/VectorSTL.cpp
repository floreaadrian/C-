#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
int main()
{
    vector <int> v; //declarare
    vector <int> :: iterator it; //declarare iterator
    int i,n,x,m,s=1;
    cin>>n;
    for(i=1;i<=n;++i) //citire
    {
        cin>>x;
        v.push_back(x);
    }
    for(it=v.begin();it!=v.end();++it) //afisare
    s=s**it;
	cout<<s<<" ";
    return 0;
}
