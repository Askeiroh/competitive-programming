#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


int32_t main() {
    int n; cin >> n; 
    if(n <= 0) { cout << "NO" << endl; return 0; }
    vector<int> gp1, gp2, ar;
    int sum = 0;

    //cout << "sum: " << sum << endl;

    if(sum % 2 != 0) { cout << "NO" << endl; return 0; }
    int curr = 0;
    int highest = n;
    
    while(curr != (sum/2)) {
        int trgt = (sum/2) - curr;
        int choosen;
        if(trgt > highest) {
            choosen = highest;
            highest--;
        } else {
            choosen = trgt;
        }
        gp2.push_back(choosen);
        curr += choosen;
    }

    for(int i : ar) {
        if(i != 0) { gp1.push_back(i); }
    }

    cout << "YES" << endl;
    
    cout << gp1.size() << endl;
    for(int i : gp1) { cout << i << " "; }
    cout << endl;

    cout << gp2.size() << endl;
    for(int i : gp2) { cout << i << " "; }
    cout << endl;
}