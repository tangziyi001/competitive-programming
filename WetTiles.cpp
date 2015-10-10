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
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

int grid[1005][1005];

queue<pi> que;
int main(){
	int x,y,t,l,w;
	while (cin >> x && x != -1){
		cin >> y >> t >> l >> w;
		memset(grid,0,sizeof(grid));
		int xl,yl;
		for (int i = 0; i < l; i++){
			cin >> xl >> yl;
			grid[xl][yl] = 1;
			que.push(make_pair(xl,yl));

		}
		int xw1, yw1,xw2,yw2;
		for (int i = 0; i < w; i++){
			cin >> xw1 >> yw1 >> xw2 >> yw2;
			grid[xw1][yw1] = -1;
			grid[xw2][yw2] = -1;
			while (xw1 != xw2 || yw1 != yw2){
				grid[xw1][yw1] = -1;
				if (xw1 < xw2){
					xw1++;
				}
				else if (xw1 > xw2){
					xw1--;
				}
				if (yw1 < yw2){
					yw1++;
				}
				else if (yw1 > yw2){
					yw1--;
				}
			}
		}

		//test
		// for (int i = 1; i <= x; i++){
		// 	for (int j = 1; j <= y; j++){
		// 		cout << grid[i][j];
		// 	}
		// 	cout << endl;
		// }
		int count = 0;
		while (!que.empty()){
			pi tmp = que.front();que.pop();
			int tx = tmp.first;
			int ty = tmp.second;
			if (grid[tx][ty] >= 0 && grid[tx][ty] <= t){
				count += 1;
				for (int i = 0; i < 4; i++){
					int ttx = tx+dir[i][0];
					int tty = ty+dir[i][1];
					if (ttx >= 1 && ttx <= x && tty >=1 && tty <= y){
						if (grid[ttx][tty] == 0){
							grid[ttx][tty] = grid[tx][ty] + 1;
							que.push(make_pair(ttx,tty));
						}
					}
				}
			}
		}
		
		cout << count << endl;
		
		// for (int i = 1; i <= x; i++){
		// 	for (int j = 1; j <= y; j++){
		// 		cout << grid[i][j];
		// 	}
		// 	cout << endl;
		// }

	}





	return 0;
}
