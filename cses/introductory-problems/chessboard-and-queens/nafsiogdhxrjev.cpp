#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define int long long

const int FAC_8 = 40320;

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    vector<int> board(8);
    vector<vector<bool>> blocks(8,vector<bool>(8));
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            char curr; cin >> curr;
            if(curr == '*') { blocks[j][i] = 1; }
        }
        board[i] = i;
    }
    int inval = 0;
    do{
        vector<int> visDiag1(15), visDiag2(15);
        for(int i = 0; i < board.size(); i++) {
            int x=i, y=board[i];
            if(blocks[x][y] || visDiag1[(x-y)+7] || visDiag2[x+y] ){
                inval++; break;
            }
            visDiag1[(x-y)+7] = 1;
            visDiag2[x+y] = 1;
        }
    } while(next_permutation(board.begin(), board.end()));
    cout << FAC_8 - inval << endl;
}