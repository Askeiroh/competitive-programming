#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
#define int ll 

void solve(){
	int n;
	cin >> n;

	vector<int> vt(n);

	for(int i = 0; i < n; i++){
		cin >> vt[i];
	}

	int tp = 0;
	int res= vt[0];
	for(int i = 1; i < n; i++){
		if(vt[i] != vt[i-1]){
			res += min(abs(vt[i] - vt[i-1]), abs(vt[i] - tp));

			if(abs(vt[i] -vt[i-1]) >= abs(vt[i] -tp)){
				tp = vt[i-1];
			}
		}
		cout << tp << " ";
	}
	cout << endl;
	cout << res << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
