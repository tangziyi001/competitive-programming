//UVA 11957
// Recursion and 2D array parameter

#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;
int path = 0;
void move(char board[][100], int ridx, int cidx, int colsz){
	if (ridx == 0){
		path += 1;
	}
	else {
		if (cidx >= 1 && board[ridx - 1][cidx - 1] == '.'){
				move(board, ridx-1, cidx-1, colsz);
		}
		if (cidx <= colsz - 2 && board[ridx - 1][cidx + 1] == '.'){
				move(board, ridx-1, cidx+1, colsz);
		}
		if (cidx >= 2 && board[ridx - 1][cidx - 1] == 'B' && ridx >= 2){
				move(board, ridx-2, cidx-2, colsz);
		}
		if (cidx <= colsz - 3 && board[ridx - 1][cidx + 1] == 'B' && ridx >= 2){
				move(board, ridx-2, cidx+2, colsz);
		}

	}
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
			
			path = 0;
			move(board, ridx, cidx, n);
			int count = path;

			cout << "Case " << i+1 <<  ": " << path << endl;
		}
	return 0;
}