#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long
const int NUM_OF_PILES = 3;

int32_t main() {
    int n; cin >> n;
    vector<stack<int>> piles(NUM_OF_PILES+1);
    vector<pair<int, int>> moves, currStatus(NUM_OF_PILES);
    for(int i = 0; i < NUM_OF_PILES; i++) { currStatus[i].second = i; piles[i].push(0); };
    for(int i = n; i > 0; i--) { piles[0].push(i); }
    int lastPile = -1;

    if(n%2 == 0){
        piles[3].push(999);
        while(piles[2].size() < n+1) {
            int currPile = 3;
            for(int i = 0; i < NUM_OF_PILES; i++) {
                currStatus[i].first = piles[i].top();
                if(i == lastPile) { continue; }
                if(piles[i].top() == 0) { continue; }
                if(piles[i].top() < piles[currPile].top()) {
                        currPile = i;
                }
            }
            int valToMove = piles[currPile].top();
            piles[currPile].pop();
            int nextPile;

            for(int i = currPile+1; i <= 3; i++) {
                //cout << "CANDIDATO ATUAL: " << i << endl;
                if(i >= 3) { i = 0; } 
                if(piles[i].top() > valToMove || piles[i].top() == 0) {
                    piles[i].push(valToMove);
                    nextPile = i;
                    break;
                }
            }

            lastPile = nextPile;
            moves.push_back({currPile+1, nextPile+1});

            //cout << "currPile: " << currPile << endl;
            //cout << "valToMove: " << valToMove << endl;
            //cout << "nextPile: " << nextPile << endl;
            //cout << endl;
        }
        cout << moves.size() << endl;
        for(pair<int, int> i : moves) { cout << i.first << " " << i.second << endl; }
        return 0;
    }

    
    while(piles[2].size() < n+1) {
        int currPile = 3;
        int secondaryPile;
        for(int i = 0; i < NUM_OF_PILES; i++) { currStatus[i].second = i; currStatus[i].first = -1; }
        for(int i = 0; i < NUM_OF_PILES; i++) {
            if(i == lastPile) { continue; }
            if(piles[i].top() == 0) { continue; }
            currStatus[i].first = piles[i].top();
        }
        sort(currStatus.begin(), currStatus.end());
        currPile = currStatus[currStatus.size()-1].second;
        int valToMove = piles[currPile].top();
        int nextPile;

        //for(pair<int, int> i : currStatus) { cout << "value: " << i.first << " " << "pile: " << i.second << endl; }
        //cout << endl;

        for(int i = currPile-1; i >= -1; i--) {
            //cout << "CANDIDATO ATUAL: " << i << endl;
            if(i <= -1) { i = 2; } 
            if(i == currPile) {
                //cout << "DEU CICLOOOO" << endl;
                currPile = currStatus[currStatus.size()-2].second;
                valToMove = piles[currPile].top();
                i = currPile-1;
                if(i <= -1) { i = 2; } 
                //cout << "NEW PILE: " << currPile << endl;
                //cout << "NEW VALUE: " << valToMove << endl;
            }
            if(piles[i].top() > valToMove || piles[i].top() == 0) {
                piles[i].push(valToMove);
                nextPile = i;
                break;
            }
        }
        piles[currPile].pop();
        lastPile = nextPile;
        moves.push_back({currPile+1, nextPile+1});
        
        //cout << "currPile: " << currPile << endl;
        //cout << "valToMove: " << valToMove << endl;
        //cout << "nextPile: " << nextPile << endl;
        //cout << endl;
    }
    cout << moves.size() << endl;
    for(pair<int, int> i : moves) { cout << i.first << " " << i.second << endl; }
}