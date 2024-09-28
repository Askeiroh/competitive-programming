#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; //number of time intervals
    int g; //time to shower
    int m; //amount of hours per day
    cin >> n >> g >> m; // MISTAKE: tried to set size of vector timeIntervals with n but n had no value yet
    vector<pair<int, int>> timeInvervals(n);
    int maxFreeTime = 0;
    string showering = "NO";

     for (int i = 0; i < n; i++) {
        //int u, v; cin >> u >> v;
        //timeInvervals.emplace_back(u, v);

        cin >> timeInvervals[i].first >> timeInvervals[i].second;

        //v[i].first = u;
        //v[i].second = v;
     }

     //check for time at the beggining of the day
    maxFreeTime = timeInvervals[0].first;

     //check for time at the end of the day
    maxFreeTime = max(maxFreeTime, m - timeInvervals[timeInvervals.size() - 1].second);

     //check for between time invertals
    for (int i = 1; i < n; i++) {
        int curr = timeInvervals[i].first - timeInvervals[i - 1].second;
        maxFreeTime = max(maxFreeTime, curr);
    }

    if (maxFreeTime >= g) {
        showering = "YES";
    }

    cout << showering << endl;
}

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