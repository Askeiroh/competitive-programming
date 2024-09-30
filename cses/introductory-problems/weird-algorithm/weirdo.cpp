#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n, curr; cin >> n;
    curr = n; cout << curr << " ";
    while(curr != 1) {
        if(curr % 2 != 0) {
            curr = curr*3 +1;
            cout << curr << " ";
        } else {
            curr = curr/2;
            cout << curr << " ";
        }
    }
}