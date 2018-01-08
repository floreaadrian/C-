#include <iosteram>

using namespace std;

int fibo1(int n) {
    int prev = 0, crt = 1;
    for (int i = 1; i < n; i++) {
    int f = crt + prev;
    prev = crt;
    crt = f;
    }
    return n == 0 ? prev : crt;
}
int fibo2(int n) {
    int prev = 0, crt = 1;
    for (int i = 0; i < n / 2; i++) {
    prev += crt;
    crt += prev;
    }
    return n % 2 == 0 ? prev : crt;
}

int fibo3(int n) {
    if (n == 0 || n == 1) {
    return n;
    }
    return fibo3(n - 2) + fibo3(n - 1);
}

int fibo4_aux(int n, int prev, int crt) {
    if (n == 0 || n == 1) {
    return n == 0 ? prev : crt;
    }
    return fibo4_aux(n - 1, crt, prev + crt);
}

int fibo4(int n) {
    return fibo4_aux(n, 0, 1);
}

int main()
{
  int n;
  cin>>n;
  cout<<fibo(n);
  return 0;
}
