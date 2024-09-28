#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

vector<vector<int>> interactions, interruptions;
vector<int> sad;
vector<int> resolved;
stack<vector<int>> q;
int lastMus, currMus, idxInter;

void ver() {
    vector<int> curr = q.top();
    q.pop();
    int timestamp, duration, skip, ident, idxAction;//, skipedAux;
    timestamp = curr[0];
    duration = curr[1];
    skip = curr[2];
    ident = curr[3] + 1;
    idxAction = curr[3];
    //skipedAux = curr[4];

    cout << "timestamp: " << timestamp << endl;
    cout << "duration: " << duration << endl;
    cout << "skip: " << skip << endl;
    cout << "ident: " << ident << endl;
    cout << "idxAction: " << idxAction << endl;
    //cout << "skipedAux: " << skipedAux << endl << endl;


    if(skipedAux == 2) { return; } // se ja foi considerado
    if(skipedAux == 1) { // é um skip que veio
        interactions[idxAction][4] = 2;
    } else if(idxAction < interactions.size()-1) { 
        q.push(interactions[idxAction+1]);
    }
    if(idxInter >= interruptions.size()) { return; }
    
    cout << "lastMus: " << lastMus << endl;

    if(timestamp > lastMus) {
        currMus = timestamp + duration;
        lastMus = currMus;
    } else {
        currMus = lastMus + duration;
        lastMus = currMus;
    }

    cout << "currMus: " << currMus << endl << endl;


    int timestampInter, durationInter, skipInter, identInter, idxActionInter, skipedAuxInter;
    timestampInter = interruptions[idxInter][0];
    durationInter = interruptions[idxInter][1];
    skipInter = interruptions[idxInter][2];
    identInter = interruptions[idxInter][3] + 1;
    idxActionInter = interruptions[idxInter][3];
    //skipedAuxInter = interruptions[idxInter][4];

    cout << "timestampInter: " << timestampInter << endl;
    cout << "durationInter: " << durationInter << endl;
    cout << "skipInter: " << skipInter << endl;
    cout << "identInter: " << identInter << endl;
    cout << "idxActionInter: " << idxActionInter << endl;
    //cout << "skipedAuxInter: " << skipedAuxInter << endl << endl;


    if(identInter == ident) {
        lastMus = timestampInter + durationInter;
        idxInter++;

        cout << "interrupção ignorada pq tentou se cancelar" << endl << endl;
        
    } else if(currMus == timestampInter) {
        lastMus = timestampInter + durationInter;
        interactions[idxActionInter][4] = 1;
        cout << "top antes " << q.top()[3]+1 << endl << endl;
        q.push(interactions[idxActionInter]);
        cout << "top dps " << q.top()[3]+1 << endl << endl;
        idxInter++;

        cout << "interrupção ignorada" << endl << endl;
        
    } else if(currMus > timestampInter) {
        //lastMus = timestampInter + durationInter;
        sad.push_back(ident);
        interactions[idxActionInter][4] = 1;
        cout << "top antes " << q.top()[3]+1 << endl << endl;
        q.push(interactions[idxActionInter]);
        cout << "top dps " << q.top()[3]+1 << endl << endl;
        idxInter++;
        
        cout << "interrupção detectada" << endl << endl;

    } 
    //else {
    //    lastMus += curr[1];
    //    cout << "sem interrupção" << endl << endl;
    //}

    cout << endl << endl;
}

void solve(){
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        int t, m, c; cin >> t >> m >> c;
        interactions.push_back({t, m, c, i, 0});
    }

    for(vector<int> i : interactions) {
        if(i[2]) {
            interruptions.push_back(i);
        }
    }

    sort(interruptions.begin(), interruptions.end());
    sort(interactions.begin(), interactions.end());

    lastMus = 0; currMus = 0; idxInter = 0;
    q.push(interactions[0]);
    resolved.resize(n, 0);

    while(!q.empty()) {
        ver();
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