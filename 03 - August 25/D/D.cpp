#include <bits/stdc++.h>
using namespace std;

int main() {
    while (true) {
        int n, m;
        int u[102][102];
        int l[102][102];
        int res[102][102];
        int mat[102][102];

        scanf ("%d %d", &n, &m);

        if (n == 0 && m == 0) break;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf ("%d", &mat[i][j]);
                if (mat[i][j] == 1)
                    u[i][j] = l[i][j] = 0;
                else u[i][j] = l[i][j] = 1;
            }
        }

        for (int i = 0; i < n; i++)
                for (int j = 0; j < m; j++) {
                    if (i-1 >= 0 && mat[i][j] == 0) u[i][j] = u[i][j] + u[i-1][j];
                    if (j-1 >= 0 && mat[i][j] == 0) l[i][j] = l[i][j] + l[i][j-1];
                }

        int menorUp, maiorUp, cont = 0, maior = 0;
        vector<pair<int,int>> pairs;
        for (int i = 0; i < n; i++) {
            menorUp = 101;
            maiorUp = 0;
            for (int j = 0; j < m; j++) {
                menorUp = u[i][j];
                for (int k = j; k >= 0; k--) {
                    menorUp = min(menorUp, u[i][k]);
                    maior = max(maior, (j-k+1)*menorUp);
                }
            }
        }

        printf("%d\n", maior);
    }

    return 0;
}
