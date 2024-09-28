#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<vector <int>> q, inter;
    vector<int>sad;

    for(int i = 0; i < n; i++) {
        int t, m, c; cin >> t >> m >> c;
        q.push_back({t, m, c, 0});
    }

    for(vector<int> i : q) {
        if(i[2]) {
            inter.push_back(i);
        }
    }

    sort(inter.begin(), inter.end());
    sort(q.begin(), q.end());

    int lastM, ind; ind = lastM = 0;
    //stack<vector<int>> nxt;
    //nxt.push;

    for(int i = 0; i < q.size(); i++) {
        vector<int> curr = q[i];
        if(ind >= inter.size() || curr[3]) { continue; }

        int currM;
        if(curr[0] > lastM) {
            currM = curr[0] + curr[1];
        } else {
            currM = lastM + curr[1];
        }

        if(curr[2]) {
            ind++;
            continue;
        }

        if(currM > inter[ind][0]) {
            lastM = inter[ind][0] + inter[ind][1];
            q[1];
            ind++;
            sad.push_back(i+1);
            continue;
        }

        lastM += curr[1];
    }

    cout << sad.size() << endl;
    for(int i : sad) {
        cout << i << endl;
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}