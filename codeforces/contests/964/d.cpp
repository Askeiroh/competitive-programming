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
    vector<char> missingChars;

    for(int i = 0; i < m.size(); i++) {
        if(m[i] == '?') {
            joker++;
            jkPointers.push_back(i);
            continue;
        }

        bool found = false;

        for(int j : s) { //will this fuck me?
            if(m[i] == s[j]) {
                m.erase(m.begin() + i);
                found = true;
                continue;
            }
        }

        if(!found) {
            missing++;

            s[i] 
        }
    }

    if(missing > joker) {
        cout << "NO" << endl;
    } else {
        for(int i; i < joker; i++) {
            answer[jkPointers[i]] = missingChars[i];
        }

        cout << "YES" << endl << answer << endl;
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
