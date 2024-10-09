#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MOD = 1e9+7;
int main() {
    int n; cin >> n;
    int res = 1;
    for(int i = 0; i < n; i++) { res = ((ll) res*2) % MOD; }
    cout << res << "\n";
}