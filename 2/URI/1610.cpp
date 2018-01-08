#include<iostream>
#include<vector>
#include<string.h>
using namespace std;
vector <int> A[10001];
int ac=0,viz[100001],nivel[100001];
void df(int nod){
    int nr,i;
    viz[nod]=1;
    nr=A[nod].size();
    for(int i=0;i<nr;i++){
        if(!viz[A[nod][i]])
        {
		viz[A[nod][i]];
		nivel[nod]=nivel[i]+1;
		if(nivel[i]<nivel[nod])
		{
			ac=1;
		}
		else df(A[nod][i]);
		}
    }
}
 
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m,x,y;
        cin>>n>>m;
        while(m--){
            cin>>x>>y;
            A[x].push_back(y);
        }
        df(1);
        if(!ac)cout<<"NAO\n";
        else cout<<"SIM\n";
        memset(viz,0,sizeof(viz));
        memset(A,0,sizeof(A));
        ac=0;
    }
    return 0;
}
