//UVA 11957
// Recursion, Dynamic Programming and 2D array parameter

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int dp[105][105];
const int mod=1000007;
int move(char board[][100], int ridx, int cidx, int colsz){
    int path=0;
    if(dp[ridx][cidx]>-1)
        return dp[ridx][cidx];
    if (ridx == 0){
        path=1;
    }
    else {
        if (cidx >= 1 && board[ridx - 1][cidx - 1] == '.'){
            path=(path+move(board, ridx-1, cidx-1, colsz))%mod;
        }
        if (cidx <= colsz - 2 && board[ridx - 1][cidx + 1] == '.'){
            path=(path+move(board, ridx-1, cidx+1, colsz))%mod;
        }
        if (cidx >= 2 && board[ridx - 1][cidx - 1] == 'B' && ridx >= 2&&board[ridx-2][cidx-2]=='.'){
            path=(path+move(board, ridx-2, cidx-2, colsz))%mod;
        }
        if (cidx <= colsz - 3 && board[ridx - 1][cidx + 1] == 'B' && ridx >= 2&&board[ridx-2][cidx+2]=='.'){
            path=(path+move(board, ridx-2, cidx+2, colsz))%mod;
        }
        
    }
    return dp[ridx][cidx]=path%mod;
}


int main(){
    int test;
    cin >> test;
    // each board
    for (int i = 0; i < test; ++i){
        char board[100][100];
        int n = 0;
        int ridx = 0;
        int cidx = 0;
        bool find = false;
        cin >> n;
        // each row
        for (int k = 0; k < n; ++k){
            cin >> board[k];
            if (find == false){
                for (int j = 0; j < n; ++j){
                    if (board[k][j] == 'W'){
                        find = true;
                        ridx = k;
                        cidx = j;
                        break;
                    }
                }
            }
        }
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                dp[j][k]=-1;
        move(board, ridx, cidx, n);
        
        cout << "Case " << i+1 <<  ": " << dp[ridx][cidx]<< endl;
    }
    return 0;
}