#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long


void solve() {
    string m, s;
    cin >> m >> s;
    bool OK = false;
    int nemo = 0; //the one I'm searching for
    for(int i = 0; i < m.size(); i++) {

        char curr = m[i];

        if(OK) {
            continue;
        }

        if(curr == '?') {
            m[i] = s[nemo];
            nemo++;

            if(nemo >= s.size()) {
                OK = true;
            }
            continue;
        }
        
        if(curr == s[nemo]) {
            nemo++;

            if(nemo >= s.size()) {
                OK = true;
            }
            continue;
        }
    }

    if(!OK) {
        cout << "NO" << endl;
        return;
    }
    for(int i = 0; i < m.size(); i++) {
        if (m[i] == '?') {
            m[i] = 'a';
        }
    }

    cout << "YES" << endl;
    cout << m << endl;
}

signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = 1;
    if (TC) {
        cin >> TC;
        while(TC--) { solve(); }
    } else {
        solve();
    }

    return 0;
}
