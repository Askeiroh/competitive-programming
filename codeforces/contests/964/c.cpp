#include <bits/stdc++.h>

using namespace std;

#define endl '\n'
#define int long long

void solve() {
    int n; //number of time intervals
    int g; //time to shower
    int m; //amount of hours per day
    string showering = "NO";
    vector<int> day(m); //will the size cause me trouble?
    vector<int> intervals(n * 2);

    cin >> n;
    cin  >> g;
    cin >> m;

    for (int i = 0; i < m; i++) {
        day[i] = i;
    }

    for (int i = 0; i < n * 2; i += 2) {
        cin >> intervals[i];
        cin >> intervals[i + 1];
    }  

    for (int i = 0; i < n; i++) { //iterate 2 
        int srtInterval = intervals[i];
        int endInterval = intervals[i + 1];

        for (int i = srtInterval; i >= endInterval; i++) { //change to signed?****
            day.erase(day.begin() + i); //long long fuck****
        }
    }

    for (int i = 0; i < day.size() - 1; i++) {
        int timRow = 0; //timepoints in a row
        bool inRow = (day[i] + 1 = day[i + 1]); //is the current day in a row? //long long fuck****

        if (inRow) { 
            timRow++;
        }
        if (timRow == g - 1) {
            showering = "YES";
        }
        if (!inRow) {
            timRow = 0;
        }
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