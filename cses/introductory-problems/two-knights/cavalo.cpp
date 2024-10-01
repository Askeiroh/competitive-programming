#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

int32_t main() {
    int n; cin >> n;
    for(int i = 1; i <= n; i++) {
        if(i == 1) { cout << 0 << endl; continue; }
        if(i == 2) { cout << 6 << endl; continue; }
        if(i == 3) { cout << 28 << endl; continue; }

        int core = (i-4)*(i-4)*8;
        int outerSlabs = (i-4)*4*4;
        int innerSlabs = (i-4)*6*4;
        int corners = ((2+3+3+4)*4);

        int totalAttacks = core + outerSlabs + innerSlabs + corners;
        int totalMoves = ((i*i*i*i)-(i*i));
        int totalValidPos = (totalMoves - totalAttacks)/2;
        cout << totalValidPos << endl;
    }
}