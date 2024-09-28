#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long


void solve() {
    int n, k; cin >> n >> k; //n year, k last

    int totalLeaves = ((2*n-k+1)*k)/2;

    if(totalLeaves % 2) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
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