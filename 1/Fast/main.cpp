#include <bits/stdc++.h>

using namespace std;

ifstream fin("ciur.in");
ofstream fout("ciur.out");

void SieveOfAtkin(int limit)
{
    int contor=0;
    if (limit > 2)  contor=1;
    if (limit > 3)  contor=2;
    bool sieve[limit];
    for (int i=0; i<limit; i++)
        sieve[i] = false;
    for (int x = 1; x*x < limit; x++)
    {
        for (int y = 1; y*y < limit; y++)
        {
            int n = (4*x*x)+(y*y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5))
                sieve[n] ^= true;

            n = (3*x*x)+(y*y);
            if (n <= limit && n % 12 == 7)
                sieve[n] ^= true;

            n = (3*x*x)-(y*y);
            if (x > y && n <= limit && n % 12 == 11)
                sieve[n] ^= true;
        }
    }

    for (int r = 5; r*r < limit; r++)
    {
        if (sieve[r])
        {
            for (int i = r*r; i < limit; i += r*r)
                sieve[i] = false;
         }
    }
    for (int a = 5; a < limit; a++)
        if (sieve[a])
           contor++;
    fout<<contor;
}
int main(void)
{
    int limit;
    fin>>limit;
    SieveOfAtkin(limit);
    return 0;
}
