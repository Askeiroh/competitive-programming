#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin >> n;
    vector<int> seq;
    for(int i = 0; i < n; i++) {
        int curr; cin >> curr;
        seq.push_back(curr);
    }
    int ans = 0;
    for(int i = 1; i < seq.size(); i++) {
        if(seq[i-1] > seq[i]) {
            int diff = seq[i-1] - seq[i];
            seq[i] += diff;
            ans += diff;
        }
    }
    cout << ans << endl;
}