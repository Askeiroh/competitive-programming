#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<char>> mapa(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mapa[i][j];
        }
    }

    pair<int, int> startCoor;
    pair<int, int> endCoor;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {  
            char currChar = mapa[i][j];
            if (currChar == 'A') {
                startCoor = {i, j};
            }
            if (currChar == 'B') {
                endCoor = {i, j};
            }
        }
    }

    queue<pair<int, int>> q;
    vector<vector<int>> d(n, vector<int>(m, 1e9));
    vector<vector<pair<int, int>>> p;

    q.push(startCoor);
    d[startCoor.first][startCoor.second] = 0; 

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        for (auto [ii, jj] : direction) {
            int ni = i + ii;
            int nj = j + jj;

            if (mapa[ni][nj] == 'B') {
                if (d[i][j] + 1 < d[ni][nj]) {
                    q.push({ni, nj});
                    d[ni][nj] = d[i][j] + 1;
                    p[ni][nj] = 
                }
            }

            if (mapa[ni][nj] == '#') {
                continue;
            }

            if (mapa[ni][nj] == '.') {
                if (d[i][j] + 1 < d[ni][nj]) {
                    q.push({ni, nj});
                    d[ni][nj] = d[i][j] + 1;
                    
                }
            }
        }
    }

    if(d[endCoor.first][endCoor.second] > n * m) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
    cout << d[endCoor.first][endCoor.second] << endl;
    cout << "PATH" << endl;

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


