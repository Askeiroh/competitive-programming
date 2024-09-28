#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int n, k; cin >> n >> k;
    vector<int> d, d2;

    for(int i = 0; i < n; i++) {
        int curr; cin >> curr;
        d.push_back(curr);
    }

    sort(d.begin(), d.end());

    for(int i = 0; i < d.size()-2; i++) {
      d2.push_back(d[i+1] - d[i]);
    }

    sort(d2.begin(), d2.end());

    int total = 0;

    for(int i = 0; i < k; i++) {
        total += pow(d2[i], 2);
    }

    cout << total << endl;d
}