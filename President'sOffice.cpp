//CodeForces 6B
// Double Array
// Note: CONSECUTIVE MEMORY FOR TWO ROWS

#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int count = 0;
	int row, col;
	char color;
	cin >> row >> col >> color;
	char line[row][col];
	vector<char> exi;
	exi.push_back(color);
	for (int i = 0; i < row; ++i){
		cin >> line[i];
	}
	for (int i = 0; i < row; ++i){
		for ( int j = 0; j < col; ++j){
			if (line[i][j] != '.'){
				if (find(exi.begin(), exi.end(), line[i][j]) == exi.end()){
					if ((j != col-1 && line[i][j+1] == color) ||
						(j != 0 && line[i][j-1] == color) ||
						(i != row-1 && line[i+1][j] == color) ||
						(i != 0 && line[i-1][j] == color) ){
						count += 1;
						exi.push_back(line[i][j]);
					}
				}
				
			}
		}
	}
	cout << count << endl;




	return 0;
}