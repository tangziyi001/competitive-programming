/*
 *	Aizu 0026
 *	Created by Ziyi Tang
 *
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
#define INF (int)1E9
#define INFL (long)1E18
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

bool check(int x, int y, int sx, int sy){
	if (x < 0 || x > sx-1 || y < 0 || y > sy-1){
		return false;
	}
	return true;
}

int main(){
	int all[10][10];
	int maxm = 0;
	memset(all,0,sizeof(all));
	string line;
	int count = 0;

	while (getline(cin, line) && line != ""){
		int x,y,sz;
		
		x = stoi(line.substr(0,1));
		y = stoi(line.substr(2,3));
		sz = stoi(line.substr(4,5));
		if (sz == 1){
			all[x][y] += 1;
			maxm = max(maxm, all[x][y]);
			for(int i = 0; i < 4;i++){
				int tx = x+ dir[i][0];
				int ty = y+ dir[i][1];
				if(check(tx,ty,10,10)){
					all[tx][ty] += 1;
					maxm = max(maxm, all[tx][ty]);
				}
			}
		}
		if (sz == 2){
			for (int i = x-1; i <= x+1; i++){
				for (int j = y-1; j <= y+1; j++){
					if(check(i,j,10,10)){
						all[i][j] += 1;
						maxm = max(maxm, all[i][j]);
					}
				}
			}
		}
		if (sz == 3){
			for (int i = x-1; i <= x+1; i++){
				for (int j = y-1; j <= y+1; j++){
					if(check(i,j,10,10)){
						all[i][j] += 1;
						maxm = max(maxm, all[i][j]);
					}
				}
			}
			if (check(x-2,y,10,10)){
				all[x-2][y] += 1;
				maxm = max(maxm, all[x-2][y]);
			}
			if (check(x+2,y,10,10)){
				all[x+2][y] += 1;
				maxm = max(maxm, all[x+2][y]);
			}
			if (check(x,y-2,10,10)){
				all[x][y-2] += 1;
				maxm = max(maxm, all[x][y-2]);
			}
			if (check(x,y+2,10,10)){
				all[x][y+2] += 1;
				maxm = max(maxm, all[x][y+2]);
			}
		}


	}
	for (int i = 0; i < 10; i++){
			for (int j =0; j < 10; j++){
				
				if (all[i][j] ==0){
					count++;
				}
			}
		}
	cout << count << endl;
	cout << maxm << endl;




	return 0;
}
