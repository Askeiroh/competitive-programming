#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    vector<int> va;
    int tot, n; cin >> n;
    tot = 0;

    for(int i = 0; i < n; i++) {
        int curr = 0;
        cin >> curr;
        tot += curr;
        va.push_back(curr);
    }

    if(n <= 2) {
        cout << -1 << endl;
        return;
    }

    sort(va.begin(), va.end());

    int mid, ava;
    
    mid = va[n/2];

    //if(n % 2 == 0) {
    //    mid = va[n/2];
    //} else {
    //    mid = va[n/2-1];
    //}

    ava = tot/n;

    if(tot > mid*n*2) {
        cout << 0 << endl;
        return;
    }

    cout << (mid*2*n)-tot+1 << endl;

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