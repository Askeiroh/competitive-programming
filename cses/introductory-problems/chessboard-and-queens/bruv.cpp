#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int FAC_8 = 40320;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> board(8), blocks(8);
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char curr; cin >> curr;
            if(curr == '*') { blocks[j] = i+1; }
        }
        board[i] = i+1;
    }
    int inval = 0, cnt=0;
    do{
        vector<int> visDiag1, visDiag2;
        cnt++;
        for(int i = 0; i < board.size(); i++) {
            if(board[i] == blocks[i]){ inval++; break; }
            int collum = i+1;
            int line = board[i];
            int currDiag1 = line-collum;
            //int currDiag2 = line+collum;
            bool f = 0;

            for(int j : visDiag1) { if(currDiag1 == j){ inval++; f=1; break; } }
            if(f) { break; }
            //for(int j : visDiag2) { if(currDiag2 == j){ inval++; continue; } }
            visDiag1.push_back(currDiag1);
            //visDiag2.push_back(currDiag2);
        }
    } while(next_permutation(board.begin(), board.end()));
    cout << FAC_8 - inval << endl;
    cout << inval << endl;
}