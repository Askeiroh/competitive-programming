#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int BIG = (1e9)+7;

int32_t main() {
    string seq; cin >> seq;
    sort(seq.begin(), seq.end());
    int diffChars = 0;
    vector<int> repetitions(26, 0);
    char last;
    int auxIndex = -1;
    for(char curr : seq) {
        if(last == curr) { repetitions[auxIndex]++; }
        diffChars++; auxIndex++;
        last = curr;
    }
    int valToMod = diffChars;
    int permu = 1;
    for(int i = valToMod; i > 1; i--) { permu = (permu*i)%BIG; }
    permu %= BIG;
    for(int i = 0; i < repetitions.size(); i++) {
        int curr = 1;
         for(int j = repetitions[i]; j > 1; j--) { curr = (curr*j)%BIG; };
        repetitions[i] = curr;
    }
    int bruv = 1;
    for(int i : repetitions) { bruv = (i*bruv)%BIG; }
    int AAAAAAAAAAa = 1;
    for(int i = 1; i < BIG-2; i++) {
        
    }
}