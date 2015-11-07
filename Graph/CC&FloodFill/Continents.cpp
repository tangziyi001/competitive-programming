/*
 *	UVA 11094
 *	Created by Ziyi Tang
 *	Scrolled DFS Flood Fill
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <list>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <bitset>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vpi> vvpi;
const int INF = (int)1E9;
const long INFL = (long)1E18;
const int dir[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

int m,n;
int x,y;
char grid[25][25];
int mark[25][25];
char wet;
char land;
int check(int x, int y){
	if (x >= 0 && x < m && y >= 0 && y < n)
		return true;
	return false;
}
int dfs(int x, int y){
	int count = 1;
	mark[x][y] = 1;
	for (int i = 0; i < 4; i++){
		int tx = x + dir[i][0];
		int ty = (y + dir[i][1] + n)%n;
		if (check(tx,ty) && mark[tx][ty] == 0 && grid[tx][ty] == land){
			count += dfs(tx,ty);
		}
	}
	return count;
}
int main(){
	while(cin >> m >> n){
		FILL(grid,0);
		FILL(mark,0);
		getchar();
		string line;
		char tmp1 = '@';
		char tmp2 = '@';
		int isrow;
		char start;
		for(int i = 0; i < m; i++){
			getline(cin,line);
			for (int j = 0; j < n; j++){
				grid[i][j] = line[j];
				if (tmp1 == '@')
					tmp1 = line[j];
				else if (tmp1 != '@' && line[j] != tmp1 && tmp2 == '@')
					tmp2 = line[j];
			}
		}
		cin >> x >> y;
		land = grid[x][y] == tmp1 ? tmp1 : tmp2;
		wet = grid[x][y] == tmp1 ? tmp2 : tmp1;
		//cout << land << wet << endl;

		
		dfs(x,y);
		int maxp = 0;

		REP(i,0,m){
			REP(j,0,n){
				if (check(i,j) && mark[i][j] == 0 && grid[i][j] == land)
					maxp = max(maxp, dfs(i,j));
			}
		}
		cout << maxp << endl;
		// White Space
		getline(cin,line);

		// REP(i,0,m){
		// 	REP(j,0,n){
		// 		cout << grid[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
		// REP(i,0,m){
		// 	REP(j,0,n){
		// 		cout << mark[i][j] << " ";
		// 	}
		// 	cout << endl;
		// }
	}	





	return 0;
}
