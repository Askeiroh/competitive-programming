#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, m;
    cin >> n >> m;

    vector<pair<int, int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
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
    vector<vector<char>> o(n, vector<char>(m));

    q.push(startCoor);
    d[startCoor.first][startCoor.second] = 0;

    map<pair<int, int>, char> atod;
    atod[{0, 1}] = 'L';
    atod[{1, 0}] = 'U';
    atod[{0, -1}] = 'R';
    atod[{-1, 0}] = 'D';

    map<char, pair<int, int>> dtoa;
    dtoa['L'] = {0, 1};
    dtoa['U'] = {1, 0};
    dtoa['R'] = {0, -1};
    dtoa['D'] = {-1, 0};

    map<char, char> revd;
    revd['L'] = 'R';
    revd['D'] = 'U';
    revd['R'] = 'L';
    revd['U'] = 'D';

    while(!q.empty()) {
        auto [i, j] = q.front();
        q.pop();

        for (auto [ii, jj] : direction) {

            int ni = i + ii;
            int nj = j + jj;

            if((ni < 0 || nj < 0) || (ni >= n || nj >= m)) {
                continue;
            }

            if (mapa[ni][nj] == 'B') {
                if (d[i][j] + 1 < d[ni][nj]) {
                    q.push({ni, nj});
                    d[ni][nj] = d[i][j] + 1;
                    o[ni][nj] = atod[{ii, jj}];
                }
            }

            if (mapa[ni][nj] == '#') {
                continue;
            }

            if (mapa[ni][nj] == '.') {
                if (d[i][j] + 1 < d[ni][nj]) {
                    q.push({ni, nj});
                    d[ni][nj] = d[i][j] + 1;
                    o[ni][nj] = atod[{ii, jj}];
                }
            }
        }
    }

    if(d[endCoor.first][endCoor.second] > n * m) {
        cout << "NO" << endl;
        return;
    }

    vector<char> path;

    pair<int, int> currPos;
    currPos = endCoor;
    while(currPos != startCoor) {
        char currD = o[currPos.first][currPos.second];
        char revD = revd[currD];
        pair<int, int> currA = dtoa[revD];

        path.push_back(revD);

        currPos.first += currA.first;
        currPos.second += currA.second;
    }

    cout << "YES" << endl;
    cout << d[endCoor.first][endCoor.second] << endl;

    reverse(path.begin(), path.end());

    for(int i = 0; i < path.size(); i++) {
        cout << path[i];
    }

    cout << endl;

}

signed main() {
    //ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 0;
    if (TC) { 
        cin >> TC;
        while (TC--) { solve(); }
    } else {
        solve();
    }

    return 0;
}


