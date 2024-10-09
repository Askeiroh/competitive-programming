#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin >> n;
    int total = 0;
    vector<int> seq;
    for(int i = 0; i < n; i++) {
        int curr;  cin >> curr;
        seq.push_back(curr);
        total += curr;
    }
    int target = total/2;
    int bestSum = 0;
    int currSum = 0;
    for(int mask = 0; mask < (1<<seq.size()); mask++) {
        currSum = 0;
        for(int i = 0; i < seq.size(); i++) {
            if((1<<i) & mask) {
                currSum += seq[i];
            }
        }
        if(abs(bestSum-(total - bestSum)) > abs(currSum-(total - currSum))) { bestSum = currSum; }
    }
    int diff = abs(bestSum-(total - bestSum));
    cout << diff << endl;
}