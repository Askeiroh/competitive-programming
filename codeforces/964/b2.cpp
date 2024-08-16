#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

int check(int a, int b) {
    if (a > b) { return 1; };
    if (a < b) { return -1; };
    if (a == b) { return 0; };
    }

void solve() {
    int sun1;
    int sun2;
    int sla1;
    int sla2;
    int numWin = 0;

    cin >> sun1;
    cin >> sun2;
    cin >> sla1;
    cin >> sla2;

    if ((check(sun1, sla1) + check(sun2, sla2)) > 0) { //MISTAKE: c++ inteprets -1 as true
        numWin++;
    }
    if ((check(sun1, sla2) + check(sun2, sla1)) > 0) {
        numWin++;
    }
    if ((check(sun2, sla1) + check(sun1, sla2)) > 0) {
        numWin++;
    }
    if ((check(sun2, sla2) + check(sun1, sla1)) > 0) {
        numWin++;
    }

    cout << numWin << endl;
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