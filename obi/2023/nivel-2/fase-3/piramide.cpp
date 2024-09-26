#include <bits/stdc++.h>
using namespace std;

#define endl "\n"

int32_t main() {
    vector<int> c;
    for(int i = 0; i < 6; i++) {
        int curr; cin >> curr;
        c.push_back(curr);
    }

    sort(c.begin(), c.end());

    do {
        int a1, a2, a3;
        a1 = c[0];
        a2 = c[1] + c[2];
        a3 = c[3] + c[4] + c[5];
        if(a1 == a2 && a2 == a3) {
            cout << "S" << endl;
            return 0;
        }
    } while(next_permutation(c.begin(), c.end()));

    cout << "N" << endl;
    return 0;
}