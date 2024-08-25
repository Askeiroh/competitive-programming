#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

const int MAX = 1e5 + 5;
int n, m;                                                                 vvvvvv
vector<int> adj[MAX];
vector<bool> vis(MAX);
bool OK = true;


void dfs(int u) {
    vis[u] = true;
    
    for(int v : adj[u]){
        if (vis[v] == 0) {
            dfs(v);
        }
}}

void solve() {
    cin >> n >> m;

    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i < n; i++) { 
        if (!vis[i]) {
            dfs(i);
        }
    }
}
1
signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = false;
    if (TC) { 
        cin >> TC;
        while (TC--) { solve(); }
    } else {
        solve();
    }

    return 0;
}