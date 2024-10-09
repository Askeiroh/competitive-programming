#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin >> n;
    vector<int> seq;
    for(int i = 0; i < n; i++) {
        int curr;  cin >> curr;
        seq.push_back(curr);
    }
    sort(seq.begin(), seq.end());
    reverse(seq.begin(), seq.end());
    int diff = 0;
    for(int i : seq) {
        int res1, res2;
        res1 = abs(diff-i); res2 = diff+i;
        cout << "i: " << i << endl;
        cout << "diff: " << diff << endl;
        if(res1 <= res2) {
            diff = res1;
        } else { diff = res2; }
        cout << "res1: " << res1 << endl;
        cout << "res2: " << res2 << endl;
        cout << endl;
    }
    cout << diff << endl;
}