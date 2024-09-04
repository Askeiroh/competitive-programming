#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

int n, k;
vector<int> memo(0, -1);
vector<int> ah;

int dp(int t) {
    if(t == 0) {
        return 0;
    }

    if(memo[t] != 0) {
        return memo[t];
    }

    //I've never seen it
    int lowestCost = 1e5;
    vector<int> costs;
    
    for(int i = 1; i <= k; i++) {
        if(t <= i) {
            cout << i << endl;
            int imediateDist = abs(ah[i] - ah[0]);
            costs.push_back(imediateDist);
            continue;
        }

        int currCost = abs(ah[t] - ah[t-i]);

        int totalCost = dp(t-i) + currCost;
        costs.push_back(totalCost);
    }

    for(int i : costs) {
        lowestCost = min(lowestCost, i);
    }

    memo[t] = lowestCost;
    return lowestCost;
}

void solve() {
    cin >> n >> k;
    memo.resize(n);

    cout << memo.size() << endl;

    for(int i = 0; i < n; i++) {
        int currStone;
        cin >> currStone;
        ah.push_back(currStone);
    }

    cout << dp(n-1) << endl;
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


