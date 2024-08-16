#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

const int MAX = 1e5 + 5;
int n, m;
vector<int> adj[MAX];
int vis[MAX];
int color[MAX];
bool OK = true;

void coloring_dfs(int u) {7
    vis[u] == 1;
    for(int v : adj[u]){
        if (vis[v] == 0) {
            color[v] = ;
    }
}}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    if (OK) {
        for (int i = 0; i < n; i++) {
            cout << color[i];
        }
    } else {
        cout << "IMPOSSIBLE";
    }
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { 
        cin >> TC;
        while (TC--) { solve(); }
    } else {
        solve();
    }

    return 0;
}