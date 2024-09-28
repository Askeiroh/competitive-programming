#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
	int n;
	cin >> n;

	vector<vector<int>> vt;

	for(int i = 0; i < n; i++){
		int init, term, b;
		cin >> init >> term >>b ;

		vt.push_back({init, term + init, b, i+1});
	}

	sort(vt.begin(), vt.end());
	stack<vector<int>> st;
	st.push(vt[0]);
	vector<int> res;

	while(st.size() <= vt.size()){
		vector<int> top = st.top(); // anterior
		int idx = top[3] -1;
		vector<int> next = vt[idx]; // que eu vou colocar

		if(next[0] > top[1] && next[2] == 0){
			int aux = next[0];
			next[0]=  top[1] +1;
			next[1] = next[0]+ next[1] - aux;

			st.push(next);
		}
		else if(next[0] > top[1]  && next[2] == 1){
			res.push_back(top[3]);
			st.push(next);
		}
		else{
			st.push(next);
		}


	}

	cout << res.size() << endl;
	for(auto v : res){
		cout << v << " ";
	}
	cout << endl;

}

int32_t main(){
    cin.tie(0)->sync_with_stdio(0);
    solve();
}
