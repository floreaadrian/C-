#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ciclueuler.in");
ofstream fout("ciclueuler.out");

vector <int> G[100005],st;

void euler(vector<int> G[],int nod, vector<int> &st)
{
    for(int i=0;i<G[nod].size();++i)
    {
        int aux=G[nod][i];
        G[nod].erase(G[nod].begin()+i);
        for(int j=0;j<G[aux].size();++j)
            if (G[aux][j]==nod){
            G[aux].erase(G[aux].begin()+j);
            break;
            }
        euler(G,aux,st);
    }
    st.push_back(nod);
}


int main()
{
    int n,m;
    fin>>n>>m;
    for(int i=1;i<=m;++i){
        int a,b;
        fin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    euler(G,1,st);
    if(st.size()==0)
        fout<<"-1\n";else
    for(int i=st.size()-1;i>0;--i)
        fout<<st[i]<<" ";
    return 0;
}
