#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

const int MAX = 1e5 + 5;
int n, m;
vector<int> adj[MAX];
vector<bool> vis(MAX);
vector<int> ept; //entrypoints

void dfs(int u) {
    vis[u] = true;
    
    for(int v : adj[u]){
        if (vis[v] == 0) {
            dfs(v);
        }
}}

void solve() {
    vector<pair<int, int>> newRoads;
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
            ept.push_back(i);

            if (ept.size() > 1) {
                int numEntries = ept.size();
                pair c(ept[numEntries - 2], ept[numEntries - 1]);

                newRoads.push_back(c);
            }
            dfs(i);
        }
    }

    cout << newRoads.size() << endl;

    for (int i = 0; i < newRoads.size(); i++) {
        int city1 = newRoads[i].first + 1;
        int city2 = newRoads[i].second + 1;

        cout << city1 << " " << city2 << endl;
    }
}

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