#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {

    //vector<int> vsun, vsla;
    //
    //for(int i = 0; i< 2; i++){
    //    cin >> vsun[i]
    //}
    //
    //for(int i = 0; i < 2; i++){}

    int sun1;
    int sun2;
    int sla1;
    int sla2;

    cin >> sun1;
    cin >> sun2;
    cin >> sla1;
    cin >> sla2;

    vector<int> vsun = {sun1, sun2};
    vector<int> vsla = {sla1, sla2};

    int numWins = 0;

    for (int i = 0; i <= 1; i++) {
        if (vsun[i] > vsla[0]) {
            if (i) {
                if (vsun[i - 1] > vsla[1]) {
                    numWins++;
                }
            } else {
                if (vsun[i + 1] > vsla[1]) {
                    numWins++;
                }
            }
        }

        if (vsun[i] > vsla[1]) {
            if (i) {
                if (vsun[i - 1] > vsla[0]) {
                    numWins++;
                }
            } else {
                if (vsun[i + 1] > vsla[0]) {
                    numWins++;
                }
            }
        }
    }
    cout << numWins << endl;
}

    //for (int i = 0; i <= 1; i++) {
    //    for (int j = 0; j <= 1; j++){
    //        if (vsun[i] > vsla[j]) {
    //            //maybe I could do it with only 1 for
    //            numWins++;
    //        }
    //    }
    //}
    //out << numWins << endl;


signed main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int TC = true;
    if (TC) {
        cin >> TC;
        while (TC--) { solve(); }
    } else {
        solve();
    }

    return 0;
}