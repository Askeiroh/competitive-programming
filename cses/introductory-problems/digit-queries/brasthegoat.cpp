#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long 


void solve() {
    int trgt; cin >> trgt;
    int rest = trgt, dig = 1;
    vector<int> reductions;
    if(rest >= 10) {
        rest -= 10;
        reductions.push_back(10);
        dig++;
    }
    for(int i = 90;  i < trgt; i *= 10) {
        if(rest >= (__int128_t)i*dig) {
            rest -= i*dig;
            reductions.push_back(i);
            dig++;
        }
    }
    int num = 0;
    if(rest > dig){ num = rest/dig; }
    for(int i : reductions) { num += i; }
    char res = to_string(num)[rest%dig];
    //cout << "trgt: " << trgt << endl;
    //cout << "rest: " << rest << endl;
    //cout << "num: " << num << endl;
    //cout << "dig: " << dig << endl;
    cout << res << endl;
}

int32_t main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int TC; cin >> TC;
    while(TC--) { solve(); }
}