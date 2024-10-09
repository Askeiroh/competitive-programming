#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int ASCII_OFFSET = 64;

int32_t main() {
    string orig; cin >> orig;
    vector<int> appCounter(27);
    for(char i : orig) {
        int curr = i-ASCII_OFFSET;
        appCounter[curr]++;
        //cout << i << ": " << curr << endl;
    }
    int oddCounter = 0;
    char oddOne;
    for(int i = 0; i < appCounter.size(); i++) {
        int curr = appCounter[i];
        if (curr%2 != 0) { 
            oddCounter++;
            oddOne = i;
        }
    }
    if(oddCounter > 1 || (oddCounter == 1 && (orig.size()%2 == 0))) { cout << "NO SOLUTION" << endl; return 0; }
    string res;
    for(int i = 0; i < appCounter.size(); i++) {
        int curr = appCounter[i];
        for(int j = curr/2; j> 0; j--) { res.push_back(i+ASCII_OFFSET); }
        appCounter[i] -= appCounter[i]/2;
    }
    if(oddCounter > 0) { 
        res.push_back(oddOne+ASCII_OFFSET);
        appCounter[oddOne]--;
    }
    for(int i = appCounter.size()-1; i > 0; i--) {
        int curr = appCounter[i];
        for(int j = curr; j> 0; j--) { res.push_back(i+ASCII_OFFSET); }
        appCounter[i] -= appCounter[i]/2;
    }

    cout << res << endl;
}
