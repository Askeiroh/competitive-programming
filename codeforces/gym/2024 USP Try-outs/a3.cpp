#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n; cin >> n;
    vector<vector<int>> inter;
    vector<int> sad;
    for(int i = 0; i < n; i++) {
        int t, m, c; cin >> t >> m >> c;
        inter.push_back({t, t+m, c, i+1});
    }

    vector<vector<int>> order;
    sort(inter.begin(), inter.end());
    order.push_back(inter[0]);

    for(int i = 0; i < n-1; i++) {
        vector<int> curr, next;
        next = inter[i+1];
        curr = order[i];
        

        if(next[0] < curr[1] && next[2] == 0) {
            next[1] = curr[1] + next[1] - next[0];
            next[0] = curr[1];
            order.push_back(next);
            continue;
        }
        if(next[0] < curr[1] && next[2] == 1) {
            sad.push_back(curr[3]);
            order.push_back(next);
            continue;
        }

        order.push_back(next);
    }
    
    //for(vector<int> i : order) {
    //    cout << i[0] << " " << i[1] << endl;
    //}

    cout << sad.size() << endl;
    for(int i : sad) {
        cout << i << " ";
    }
    cout << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}