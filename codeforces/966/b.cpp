#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    string res = "YES";
    vector<int> seated;
    vector<int> pos;
    bool OK = false;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int seat;
        cin >> seat;
        pos.push_back(seat);
    }

    seated.push_back(pos[0]);

    for (int i = 1; i < n; i++) {
        int curr = pos[i];
        seated.push_back(curr);

        for (int j = 0; j < seated.size(); j++) {
            if (seated[j] == curr +1 || seated[j] == curr -1) {
                OK = true;
                break;
            }
        }
        if (!OK) {
            res = "NO";
        } 
        OK = false;
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