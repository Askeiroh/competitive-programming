#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

vector<vector<int>> av;
vector<vector<int>> memo;

int dp(int d, int a) {
    if(d == 0) {
        return av[d][a];
    }

    if(memo[d][a] != -1) {
        return memo[d][a];
    }

    vector<int> opts = {0, 1, 2};
    vector<int> nxts;

    for(int i = 0; i < opts.size(); i++) {
        if(opts[i] != a) {
            nxts.push_back(opts[i]);
        }
    }

    int maxSats = max(dp(d-1, nxts[0]) + av[d][a], dp(d-1, nxts[1]) + av[d][a]);
    memo[d][a] = maxSats;
    return maxSats;
}

void solve() {
    int n;
    cin >> n;

    memo.assign(n, vector<int>(3, -1));
    av.assign(n, vector<int>(3));

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 3; j++) {
            int curr;
            cin >> curr;
            av[i][j] = curr;
        }
    }

    int ld = n-1;
    int maxValue = max({dp(ld, 0), dp(ld, 1), dp(ld, 2)});
    cout << maxValue << endl;
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


