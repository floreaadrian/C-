#include <iostream>
#include <time.h>
#include <set>
#include <stdlib.h>

using namespace std;


multiset<int> nrMultiple;
pair<set<int>::iterator,bool>rezultatSet;
multiset<int>::iterator rezultatMultiSet;

struct cmp{
    bool operator () (const int &x,const int &y) const
    {
    return x>y;
    }
};
int main()
{
    for(int i=1;i<=5;i++){
        int a;
        cin>>a;
        nrMultiple.insert(a);
    }
    int b;
    cin>>b;
    std::multiset<int>::iterator it;
    int c=nrMultiple.count(b); //de cate ori gasim elementul b in multiset
    for(int i=1;i<=c;i++)
    {it=nrMultiple.find(b); //il cautam
    nrMultiple.erase (it);} //il stergem
    cout<<"L-am gasit de "<<c<<" ori\n";
    for(it=nrMultiple.begin();it!=nrMultiple.end();++it)
    cout<<*it<<" ";
    return 0;
}
