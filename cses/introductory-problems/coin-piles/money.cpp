#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

void solve() {
    int a, b; cin >> a >> b;
    if((a == 0 || b == 0) && (a != 0 || b != 0)) { cout << "NO" << endl; return; }
    int mul = b*(-2);
    int sum = a + mul;
    if(sum % (-3) != 0) { cout << "NO" << endl; return; }
    int m, n;
    m = sum/(-3);
    n = (a-m)/2;
    //cout << "m e n:" << m << " " << n << endl;
    if((n < 0 || m < 0)) { cout << "NO" << endl; return; }
    if(b != (2*m)+n) { cout << "NO" << endl; return; }
    cout << "YES" << endl;
}

int32_t main() {
    int TC; cin >> TC;
    ios_base::sync_with_stdio(0);cin.tie(0);
    while(TC--) { solve(); }
}