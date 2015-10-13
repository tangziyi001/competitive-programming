/*
 *	UVA 11951
 *	Created by Ziyi Tang
 *	2D Max Subrectangle
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

ll grid[105][105];

int main(){
	int test;
	cin >> test;
	for (int a = 1; a <= test; a++){
		int n, m, p;
		memset(grid,0,sizeof(grid));
		cin >> n >> m >> p;

		ll price;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				cin >> price;
				grid[i][j] = price;
				grid[i][j] += grid[i-1][j] + grid[i][j-1] - grid[i-1][j-1];
			}
		}

		ll minp = 0;
		ll size = 0;
		for (int i = 1; i <= n; i++){
			for (int j = 1; j <= m; j++){
				for (int k = i; k <= n; k++){
					for (int l = j; l <= m; l++){
						ll tmp = grid[k][l] - grid[i-1][l] - grid[k][j-1] + grid[i-1][j-1];
						if (tmp > p){
							break;
						}
						else{
							ll tmpsize = (k-i+1)*(l-j+1);
							if (tmpsize > size){	
								size = tmpsize;
								minp = tmp;		
							}
							else if(tmpsize == size){
								minp = min(minp, tmp);
							}
							
						}
					}
				}
			}
		}
		cout << "Case #" << a << ": " << size << " " << minp << endl;
	}




	return 0;
}
