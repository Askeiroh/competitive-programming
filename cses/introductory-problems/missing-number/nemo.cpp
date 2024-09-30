#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin >> n; n--;
    vector<int> sq;
    for(int i = 0; i < n; i++) {
        int curr; cin >> curr;
        sq.push_back(curr);
    }
    sort(sq.begin(), sq.end());
    for(int i = 1; i < sq.size(); i++) {
        if(sq[i] != sq[i-1] + 1) {
            cout << sq[i]-1 << endl;
        }
    }
}