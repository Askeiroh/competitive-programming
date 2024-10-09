#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int32_t main() {
    int n; cin >> n;
    int res = 0;
    for(int i = 5; i <= n; i = i*5) {
        res += (n/i);
    }
    cout << res << endl;
}

//int32_t main() {
//    while(1) {
//        int n; cin >> n;
//        int res = 1;
//        for(int i = n; i > 1; i--) { res = res*i; }
//        cout << res << endl;
//    }
//}