#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  int cont = 0;
  scanf ("%d", &n);
  for (int i = 1; i <= n; i++) {
    if (i * i <= n) cont += i;
    else cont+= n / i;
  }

  printf("%d\n", cont);
  return 0;
}
