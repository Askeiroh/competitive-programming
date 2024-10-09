#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

string intToBin(int num, int n) {
    string res;
    while(num >= 1) {
        res.push_back((num%2)+48);
        num = num/2;
    }
    while(res.size() != n) { res.push_back('0'); }
    reverse(res.begin(), res.end());
    return res;
}

int32_t main() {
    int n; cin >> n;
    int last = 1 << n;
    vector<int> order;
    for(int i = 0; i < last; i++) { order.push_back(i); }

    for(int i = 2; i < last; i = i*2) { //group size
        for(int j = i; j < last; j += i*2) { //alternate trough groups
            reverse(order.begin()+j, order.begin()+j+i); } }

    for(int i : order) { cout << intToBin(i, n) << endl; }
}