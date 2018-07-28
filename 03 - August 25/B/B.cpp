#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, t, aux;
  scanf("%d %d", &n, &t);

  bool igual = false, menor = false, maior = false;

  for (int i = 0; i < n; i++) {
    scanf ("%d ", &aux);
    if (aux == t) igual = true;
    else if (aux < t) menor = true;
    else maior = true;
  }

  if (igual) printf("1\n");
  else if (menor && maior) printf("2\n");
  else printf("-1 ");

  return 0;
}
