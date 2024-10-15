#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int BIG = (1e9)+7;

int32_t main() {
    string seq; cin >> seq;
    sort(seq.begin(), seq.end());
    int numGroups = 0;
    int repetitions = 0;
    char last;
    for(char curr : seq) {
        if(last == curr) { repetitions++; }
        numGroups++;
        last = curr;
    }
    int valToMod = numGroups - repetitions;
    int res = 1;
    for(int i = valToMod; i > 1; i--) { res = (res*i)%BIG; }
    res %= 10;
    cout << res << endl;
}