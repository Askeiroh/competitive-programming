#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin >> n;
    vector<int> ans;

    if(n == 2 || n == 3) { cout << "NO SOLUTION" << endl; return 0; }
    for(int i = 2; i <= n; i += 2) { ans.push_back(i); }
    for(int i = 1; i <= n; i += 2) { ans.push_back(i); }
    for(int i : ans) { cout << i << " "; }
    cout << endl;
}