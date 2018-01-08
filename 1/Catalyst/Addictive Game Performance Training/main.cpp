#include <fstream>

using namespace std;

ifstream fin("level1-1.in");
ofstream fout("date.out");

int main()
{
    int t;
    fin>>t;
    while(t--)
    {
        int a[250][250],n,m;
        fin>>n>>m;
        int nrp;
        fin>>nrp;
        for(int i=1;i<=nrp;++i){
            int pos,cul;
            fin>>pos>>cul;
            if(pos%m==0)
            a[pos/m][m]=cul;
            else a[(pos/m)+1][pos%m]=cul;
        }
        int ccc;
        fin>>ccc;
        for(int i=1;i<=n;++i)
        {for(int j=1;j<=m;++j)
        fout<<a[i][j]<<" ";
        fout<<"\n";}
        for(int i=1;i<=m+1;++i)
            fout<<"--";
        fout<<"\n";
    }
    return 0;
}
