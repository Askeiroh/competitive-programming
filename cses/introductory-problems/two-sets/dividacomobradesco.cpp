#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"


int32_t main() {
    int n; cin >> n; 
    if(n <= 0) { cout << "NO" << endl; return 0; }
    vector<int> gp1, gp2;
    int sum = 0;

    for(int i = 1; i <= n; i++) { gp1.push_back(i); sum += i; }
    //for(int i : gp1) { cout << i << " "; } cout << endl;
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
            gp1[choosen-1] = 0;
        } else {
            choosen = trgt;
            gp1[choosen-1] = 0;
        }
        gp2.push_back(choosen);
        curr += choosen;
    }

    cout << "YES" << endl;
    
    cout << gp1.size() - gp2.size() << endl;
    for(int i : gp1) { 
        if(i != 0) {
            cout << i << " "; 
        }}
    cout << endl;

    cout << gp2.size() << endl;
    for(int i : gp2) { cout << i << " "; }
    cout << endl;
}