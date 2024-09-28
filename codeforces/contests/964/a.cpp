#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int a;
    cin >> a;

    string as = std::to_string(a);
    int fval = as[0] - '0';
    int sval = as[1] - '0';

    int result =  fval + sval;

    cout << result << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = true;
    if (TC) {
        cin >> TC;
        while (TC--) { solve(); }
    } else {
        solve();
    }

    return 0;
}
