#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n, ans = 1, e = 0, o = 0; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(v[i]&1 && v[i] != 1)
            o++;
        else if(v[i] != 1)
            e++;
    }
    if(e && o){
        cout << 2 << '\n';
    }
    else if(e){
        cout << 1 << '\n';
    }
    else if(o){
        cout << 2 << '\n';
    }
    else{
        cout << 1 << '\n';
    }
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}