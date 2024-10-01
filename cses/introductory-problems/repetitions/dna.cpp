#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    string seq; cin >> seq;
    int curr = 1; int ans = 1;
    for(int i = 1; i < seq.size(); i++) {
        if(seq[i] == seq[i-1]) {
            curr++;
        } else {
            ans = max(ans, curr);
            curr = 1;
            }
    }  
    ans = max(ans, curr);
    cout << ans << endl;
}