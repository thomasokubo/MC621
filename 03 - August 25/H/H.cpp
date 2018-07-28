#include <bits/stdc++.h>
using namespace std;

long long levels;
pair<long long, long long> tree[(long long)1e6+3];
long long weight[(long long)1e6+3];
long long levelWeight[(long long)1e6+3];
long long levelNodes[(long long)1e6+3];
long long res[(long long)1e6+3];

void setLevel(long long root, long long level) {
    if (root == -1) return;

    levelWeight[level] += weight[root];
    levelNodes[root] = level;

    setLevel(tree[root].first, level+1);
    setLevel(tree[root].second, level+1);

    levels = max(level, levels);
}

void sumWeight(long long root, long long level) {
    if (root == -1) return;

    levelWeight[level] += weight[root];

    sumWeight(tree[root].first, level+1);
    sumWeight(tree[root].second, level+1);
}

void decayWeight(long long root, long long level) {
    if (root == -1) return;

    levelWeight[level] -= weight[root];

    decayWeight(tree[root].first, level+1);
    decayWeight(tree[root].second, level+1);
}

int main() {
    long long n, m, u, v, w;
    cin >> n >> m >> w;

    levels = 0;
    weight[1] = w;

    for (long long i = 0; i < 1e6+2; i++) {
        tree[i].first = tree[i].second = -1;
        levelWeight[i] = 0;
        res[i] = -1;
    }

    for (long long i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        if (tree[v].first == -1) tree[v].first = u;
        else tree[v].second = u;

        weight[u] = w;
    }

    setLevel(1, 0);

    while (m--) {
        cin >> u;

        long long maior = 0;
        if (res[u] == -1) {
            decayWeight(u, levelNodes[u]);

            for (long long i = 0; i <= levels; i++) {
                maior = max(maior, levelWeight[i]);
            }

            sumWeight(u, levelNodes[u]);
            res[u] = maior;
        }

        cout << res[u] << endl;
    }

    return 0;
}
