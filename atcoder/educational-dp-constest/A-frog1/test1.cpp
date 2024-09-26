#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long


void solve() {
    int n;
    cin >> n;

    vector<int> stones(n);

    for(int i = 0; i < n; i++) 
        cin >> stones[i];
    

    //stonenum, total cost
    vector<int> dp(n);

    dp[0] = 0;

    for(int i = 0; i < n; i++) {
        int costJump1, costJump2;
        costJump1 = 10e9;
        costJump2 = 10e9;

        if(i == n) {

            continue;
        }

        if(i <= n - 2) {
            costJump2 = abs(stones[i] - stones[i+2]);
        }
            costJump1 = abs(stones[i] - stones[i+1]);
        

        dp[i] = min(dp[i+1] +  costJump1, dp[i+2] + costJump2);
    }

    for (int i = 0; i < dp.size(); i++) {
        cout << dp[i] << endl;
    }

    //cout << dp[n - 1] << endl;
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

