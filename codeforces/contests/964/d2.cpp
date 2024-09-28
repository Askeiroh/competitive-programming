#include <bits/stdc++.h>

using namespace std;

#define endl '/n'
#define int long long

void solve() {
    string m, s;
    cin >> m >> s;
    string answer = m;
    
    int joker = 0;
    int missing = 0;
    vector<int> jkPointers;
    vector<char> msChars;

    for(int i = 0; i < s.size(); i++) {
        bool found = false;

        for(int j = 0; j < m.size(); j++) { //will this fuck me?
            if(m[j] == '?') {
                joker++;
                jkPointers.push_back(i);
                continue;
            }

            if(s[i] == m[j]) {
                m.erase(m.begin() + j);
                found = true;
                continue;
            }
        }

        if(!found) {
            missing++;

            msChars.push_back(s[i]);
        }
    }

    if(missing > joker) {
        cout << "NO" << endl;
    } else {
        for(int i; i < missing; i++) {
            answer[jkPointers[i]] = msChars[i];
        }

        cout << "YES" << endl;
        cout << answer << endl;
    }
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
