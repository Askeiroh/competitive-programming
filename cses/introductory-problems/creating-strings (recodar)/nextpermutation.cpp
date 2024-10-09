#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    string testago; cin >> testago;
    vector<string> res;
    sort(testago.begin(), testago.end());
    do {
        res.push_back(testago);
    } while(next_permutation(testago.begin(), testago.end()));
    cout << res.size() << endl;
    for(string i : res) { cout << i << endl; }
}