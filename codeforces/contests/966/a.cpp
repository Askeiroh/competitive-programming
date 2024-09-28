#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long


void solve() { 
    int num;
    string pt1;
    string pt2;
    cin >> num;
    string t = to_string(num);
    string res = "YES";


    for (int i = 0; i < t.length(); i++) {
        if (i <= 1) {
            pt1 = pt1 + t[i];
        } else {
            pt2 = pt2 + t[i];
        }
    }

    if (pt2.empty()) {
        cout << "NO" << endl;
        return;
    }

    if (pt2[0] == '0'){
        res = "NO";
    }

    signed ipt1 = stoi(pt1);
    signed ipt2 = stoi(pt2);


    if (ipt1 != 10) {
        res = "NO";
    }

    if (ipt2 < 2) {
        res = "NO";
    }

    cout << res << endl;
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