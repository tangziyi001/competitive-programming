/*
 *	UVA 10827
 *	Created by Ziyi Tang
 *	Torus Matrix, Max Subrectangle
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
#define INF 1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

ll grid[160][160];
int main(){
	int test;
	cin >> test;
	while (test--){
		memset(grid,0,sizeof(grid));
		int r;
		cin >> r;
		int tmp;
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= r; j++){
				cin >> tmp;
				grid[i][j] = tmp;
				grid[i+r][j] = tmp;
				grid[i][j+r] = tmp;
				grid[i+r][j+r] = tmp;
			}
		}
		for (int i = 1; i <= 2*r; i++){
			for (int j = 1; j <= 2*r; j++){
				int prefix = grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
				grid[i][j] += prefix;

			}
		}

		int max = -999999;
		for (int i = 1; i <= r; i++){
			for (int j = 1; j <= r; j++){
				for (int k = i; k <= i+r-1; k++){
					for (int l = j; l <= j+r-1; l++){
						int tmpsum = grid[k][l] - grid[i-1][l] - grid[k][j-1] + grid[i-1][j-1];
						if (tmpsum > max){
							max = tmpsum;
						}
					}
				}
			}
		}
		cout << max << endl;
	}




	return 0;
}
