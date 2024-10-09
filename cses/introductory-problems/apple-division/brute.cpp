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
    sort(seq.begin(), seq.end());
    do{
        int lasti, lastSeqRem, currSeqRem;
        currSeqRem = 0;
        int sum = 0;
        int i = 0;
        for(int j = lasti; j < seq.size(); j++) { currSeqRem += seq[j]; }
        if(lastSeqRem == currSeqRem) { i++; continue; };
        while(sum < target) {
            if(sum + seq[i] <= target) {
                sum += seq[i];
                i++; 
            } else {
                int lasti = i;
                lastSeqRem = 0;
                for(int j = i; j < seq.size(); j++) { lastSeqRem += seq[j]; }
                break; 
            }
        }
        if(abs(bestSum-(total - bestSum)) > abs(sum-(total - sum))) { bestSum = sum; }
    }while(next_permutation(seq.begin(), seq.end()));
    int diff = abs(bestSum-(total - bestSum));
    cout << diff << endl;
}