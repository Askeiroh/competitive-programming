#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n, k; cin >> n >> k;
    int r, total;
    r = total = 0;
    vector<int> ppl;

    for(int i = 0; i < n; i++) {
        int t; cin >> t;
        ppl.push_back(t);
    }


    for(int i : ppl) {
        if(i == 0 && r > 0) {
            r--;
            total++;
            continue;
        }
        if(i >= k) {
            r += i;
        }
    }

    cout << total << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) { 
        cin >> TC;
        while (TC--) { solve(); }
    } else {
        solve();
    }

    return 0;
}