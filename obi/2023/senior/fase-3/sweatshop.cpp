#include <bits/stdc++.h>
using namespace std;
#define endl "\n"

int main() {
    int n, m; cin >> n >> m;
    vector<int> vn, vm;
    for(int i = 0; i < n; i++) {
        int curr; cin >> curr;
        vn.push_back(curr);
    }

    for(int i = 0; i < m; i++) {
        int curr; cin >> curr;
        vm.push_back(curr);
    }

    sort(vn.begin(), vn.end());
    sort(vm.begin(), vm.end());
    reverse(vm.begin(), vm.end());

    int total = 0;

    for(int i = 0; i < n-m; i += m) {
        for(int j = 0; j < m; j++) {
            total += vm[j]*vn[i+j]+total;
            cout << vm[j] << " " << vn[i+j] << endl;
        }
    }

    cout << total << endl;
}