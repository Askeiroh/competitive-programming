#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int y, x; cin >> x >> y;
    if(y >= x) {
        int alt = -1;
        if(y % 2 == 1) { alt = 1; }
        int esp = y*y - (y-1);
        int ans = esp + alt*(y-x);
        cout << ans << endl;
    }

    if(y < x) {
        int alt = -1;
        if(x % 2 == 0) { alt = 1; }
        int esp = x*x - (x-1);
        int ans = esp + alt*(x-y);
        cout << ans << endl;
    }
}

int32_t main() {
    int TC; cin >> TC;
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(TC--) { solve(); }
}