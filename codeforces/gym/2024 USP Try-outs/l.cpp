#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll
#define endl '\n'

void solve(){
	int n;
	cin >> n;

	vector<int> vt(n);

	for(int i = 0; i < n; i++){
		cin >> vt[i];
	}

	sort(vt.begin(), vt.end());

	int res = 0;
	int pos = 0;
	for(int i = 0; i < n;i++){
		if((n-i) * vt[i] > res){
			res = (n-i)*vt[i];
			pos = i;
		}
	}
	
	cout << vt[pos] << " "<< res << endl;
}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
