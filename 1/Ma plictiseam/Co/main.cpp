#include <fstream>
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

ofstream fout("date.out");

char co[]= {'b','c','d','e','f','g','h','i','j','a','5','&','$','#','e','f','g','h','i','j','k','l','m','n','<','>'};
char ca[]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

int finda(char s)
{
    int fi=0,la=25,mid;
    while(fi<=la){
        mid=(fi+la)/2;
        if(ca[mid]==s)
            return mid;
        else if(ca[mid]>s)
            la=mid-1;
        else fi=mid+1;
    }
}

int findo(char s)
{
    for(int i=0;i<26;++i)
        if(s==co[i])
        return i;
}

void code()
{
    char s[256];
    cout<<"Introduce textul: ";
    getline(cin,s);
    fout<<s<<" decodat in ";
    int l=strlen(s);
    for(int i=0;i<l;++i)
    {
        int re=finda(s[i]);
        s[i]=co[re];
    }
    cout<<"Textul codat v-a fi gasit in fisierul 'date.out'\n";
    fout<<s<<'\n';
}

void decode()
{
    char s[256];
    cout<<"Introduce textul: ";
    char c;
    int i=0;
    cin>>c;
    s[i]=c;
    while(c!='\n'){
        cin>>c;
        s[i++]=c;
    }
    fout<<s<<" codat in ";
    int l=strlen(s);
    for(int i=0;i<l;++i)
    {
        int re=findo(s[i]);
        s[i]=ca[re];
    }
    cout<<"Textul decodat v-a fi gasit in fisierul 'date.out'\n";
    fout<<s<<'\n';
}

int main()
{
    int var=2;
    while(var)
    {
    cout<<"Daca codezi scrie 1,daca decodezi scrie 2,iar daca vrei sa iesi scrie 3\nVarianta ta este: ";
    cin>>var;
    star:
    if(var==3)
    {
        cout<<"Bye :)";
        fout.close();
        return 0;
    }
    while(var!=1 && var!=2)
    {
        bool ok=false;
        while(cin.fail())
        {
            cout<<"Urat\n";
            cin.clear();
            cin.ignore(256,'\n');
            cin>>var;
            ok=true;
        }
        if(!ok) {cout<<"De ce faci asa?\nMai incearca\n";
        cin>>var;}
        if(var==3) goto star;
    }
    if(var==1) code();
    else if(var==2) decode();
    }
    fout.close();
    return 0;
}
